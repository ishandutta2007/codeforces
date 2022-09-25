#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int G=3;
#define N 103
typedef long long ll;
typedef unsigned long long ull;
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
int n,m,K;
struct Matrix{
	int g[N][N];
	Matrix(){memset(g,0,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					c.g[i][j]=(c.g[i][j]+1LL*a.g[i][k]*b.g[k][j])%(mod-1);
				}
			}	
		}
		return c;
	}
}e,s,pre;
int qpow(int a,int b,const int mod){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int BSGS(int a,int b,int p){
	static map<int,int> mp;
	mp.clear();
	int m=ceil(sqrt(p));
	int tmp=1;
	for(int i=0;i<m;++i){
		mp[1LL*tmp*b%p]=i;
		tmp=1LL*tmp*a%p;
	}
	int t=tmp;
	for(int i=1;i<=m;++i){
		if(mp.count(t)){
			return i*m-mp[t];
		}
		t=1LL*t*tmp%p;
	}
	return -1;
}
void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int Tong(int a,int b,int c){
	int g=__gcd(a,b);
	if(c%g)return -1;
	a/=g,b/=g,c/=g;
	int x,y;
	exgcd(a,b,x,y);
	x=1LL*c*(x%b+b)%b;
	return x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		s.g[i][1]=read();
		e.g[i][i]=1;
	}
	for(int i=1;i<n;++i){
		s.g[i][i+1]=1;
	}
	m=read(),K=read();
	pre.g[1][1]=1;
	int t=(pre*mpow(s,m-n)).g[1][1];
	int B=BSGS(G,K,mod);
	int A=Tong(t,mod-1,B);
	if(A==-1){
		return !printf("-1\n");
	}
	int ans=qpow(G,A,mod);
	printf("%d\n",ans);
	return 0;
}