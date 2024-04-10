#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 2020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
char s[N][N];
int n,m,d0[N][N],d1[N][N],mn0[N][N],mn1[N][N],ans;
int l[N][N],r[N][N]; 
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			d0[i][j]=(s[i][j]==s[i-1][j]?d0[i-1][j]+1:1);
		}
		for(int i=n;i>=1;--i){
			d1[i][j]=(s[i][j]==s[i+1][j]?d1[i+1][j]+1:1);
		}
	}
	for(int i=1;i<=n;++i){
		mn0[i][0]=mn1[i][m+1]=inf;
		for(int j=1;j<=m;++j){
			l[i][j]=(s[i][j]==s[i][j-1]?l[i][j-1]+1:1);
			mn0[i][j]=min(mn0[i][j-1],min(d0[i][j],d1[i][j])-j);
		}
		for(int j=m;j>=1;--j){
			r[i][j]=(s[i][j]==s[i][j+1]?r[i][j+1]+1:1);
			mn1[i][j]=min(mn1[i][j+1],min(d0[i][j],d1[i][j])+j);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int pre=ans;
			ans+=min(min(j+mn0[i][j],mn1[i][j]-j),min(l[i][j],r[i][j]));
		}
	}
	printf("%d\n",ans);
	return 0;
}