#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
#define N 10
int n,m,ans;
char s[N][N];
inline int calc(int x,int y){
	if(y==m)return 1;
	if(x==n)return 0;
	int t0=23333,t1=23333;
	for(int i=x;i<=n;++i){
		for(int j=y;j<=m;++j){
			if(s[i][j]=='*'){
				if(i>x)t0=min(t0,i-x-1+j-y);
				if(j>y)t1=min(t1,i-x+j-y-1);
			}
		}
	}
	return t0<t1;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	int x=1,y=1;
	while(true){
		ans+=s[x][y]=='*';
		if(x==n&&y==m)break;
		calc(x,y)?++x:++y;
	}
	printf("%d\n",ans);
	return 0;
}