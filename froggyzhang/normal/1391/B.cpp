#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int T,n,m;
char s[N][N];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<n;++i){
			ans+=(s[i][m]!='D');
		}
		for(int i=1;i<m;++i){
			ans+=(s[n][i]!='R');
		}
		printf("%d\n",ans);
	}
	return 0;
}