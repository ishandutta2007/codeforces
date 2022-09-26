#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 3003
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
int n,m,A,B,x,y,z,g[N*N],a[N][N];
int f[N][N],q[N],l,r;
ll ans;
int main(){
	n=read(),m=read(),A=read(),B=read();
	g[0]=read(),x=read(),y=read(),z=read();
	for(int i=1;i<=n*m;++i){
		g[i]=(1LL*g[i-1]*x+y)%z;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=g[(i-1)*m+j-1];
		}
	}
	for(int i=1;i<=n;++i){
		l=1,r=0;
		for(int j=1;j<=m;++j){
			while(l<=r&&j-q[l]>=B)++l;
			while(l<=r&&a[i][j]<=a[i][q[r]])--r;
			q[++r]=j;
			if(j>=B)f[i][j]=a[i][q[l]];
		}
	}
	for(int j=B;j<=m;++j){
		l=1,r=0;
		for(int i=1;i<=n;++i){
			while(l<=r&&i-q[l]>=A)++l;
			while(l<=r&&f[i][j]<=f[q[r]][j])--r;
			q[++r]=i;
			if(i>=A)ans+=f[q[l]][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}