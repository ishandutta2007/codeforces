#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
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
struct Matrix{
	ll g[6][6];
	int n;
	Matrix(int _n=0){
		n=_n;
		memset(g,0,sizeof(g));
	}
	void clear(){
		memset(g,0,sizeof(g));
	}
	Matrix operator *(const Matrix a)const{
		Matrix b(n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					b.g[i][j]=(b.g[i][j]+g[i][k]*a.g[k][j]%(mod-1))%(mod-1);
				}
			}
		}
		return b;
	}
	void Output(){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cerr<<g[i][j]<<" ";
			}
			cerr<<endl;
		}
		cerr<<endl;
	}
}beg,s;
ll n,f[4],c,ans;
Matrix mpow(Matrix a,ll b){
	Matrix ans(a.n);
	for(int i=1;i<=a.n;++i)ans.g[i][i]=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read();
	f[1]=read(),f[2]=read(),f[3]=read();
	c=read();
	s.n=beg.n=3;
	beg.g[1][1]=0,beg.g[2][1]=0,beg.g[3][1]=1;
	s.g[1][1]=s.g[1][2]=s.g[1][3]=s.g[2][1]=s.g[3][2]=1;
	ans=1;
	ans=ans*(qpow(f[1],(mpow(s,n-3)*beg).g[1][1]))%mod;
	
	s.clear();
	beg.g[1][1]=0,beg.g[2][1]=1,beg.g[3][1]=0;
	s.g[1][1]=s.g[1][2]=s.g[1][3]=s.g[2][1]=s.g[3][2]=1;
	ans=ans*(qpow(f[2],(mpow(s,n-3)*beg).g[1][1]))%mod;
	
	s.clear();
	beg.g[1][1]=1,beg.g[2][1]=0,beg.g[3][1]=0;
	s.g[1][1]=s.g[1][2]=s.g[1][3]=s.g[2][1]=s.g[3][2]=1;
	ans=ans*(qpow(f[3],(mpow(s,n-3)*beg).g[1][1]))%mod;
	
	s.clear();
	beg.clear();
	s.n=beg.n=5;
	beg.g[4][1]=3,beg.g[5][1]=1;
	s.g[1][1]=s.g[1][2]=s.g[1][3]=s.g[2][1]=s.g[3][2]=s.g[4][4]=s.g[4][5]=s.g[5][5]=1;
	s.g[1][4]=2,s.g[1][5]=mod-1-4;
	ans=ans*(qpow(c,(mpow(s,n-3)*beg).g[1][1]))%mod;
	cout<<ans<<endl;
	return 0;
}