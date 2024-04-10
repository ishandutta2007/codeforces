#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 111
const int mod=1e9+7;
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
int p,n,m,t,a[N],B;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
struct Matrix{
	int g[N][N];
	Matrix(){memset(g,0,sizeof(g));};
	Matrix operator *(const Matrix a){
		Matrix b;
		for(int i=0;i<=t;++i){
			for(int j=0;j<=t;++j){
				for(int k=0;k<=t;++k){
					b.g[i][j]=(b.g[i][j]+1LL*g[i][k]*a.g[k][j])%mod;
				}
			}
		}
		return b;
	}
}e,pre,ans,s;
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),m=read();
	p=qpow(n*(n-1)/2,mod-2);
	for(int i=1;i<=n;++i){
		a[i]=read();
		t+=a[i];
	}
	if(!t||t==n){
		printf("1\n");
		return 0;
	}
	for(int i=n;i>=n-t+1;--i){
		B+=a[i];
	}
	for(int i=1;i<=t;++i)e.g[i][i]=1;
	pre.g[B][1]=1;
	for(int j=0;j<=t;++j){
		int p1=(1LL*(t-j)*(t-j)%mod)%mod*p%mod;
		int p2=(1LL*j*(n+j-2*t)%mod)*p%mod;
		int p3=(mod+1-(p1+p2)%mod)%mod;
		if(j<t)s.g[j+1][j]=p1;
		if(j>0)s.g[j-1][j]=p2;
		s.g[j][j]=p3;
	}
	ans=mpow(s,m)*pre;
	printf("%d\n",ans.g[t][1]);
	return 0;
}