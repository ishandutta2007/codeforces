#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define P 998244353
#define G 3
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,k,p[N];int a[18][N],s[N];ll g[30],ng[30],inv;
ll qk(ll a,int b){ll t=1;for(;b;b>>=1,a=a*a%P)if(b&1)t=t*a%P;return t;}
void NTT(int*a,int n,bool t){
	for(int i=1,j=0;i<n-1;++i){
		for(int s=n;j^=s>>=1,~j&s;);
		if(i<j)swap(a[i],a[j]);
	}
	for(int d=0;(1<<d)<n;++d){
		int m=1<<d,m2=m<<1;ll _w=t==1?g[d]:ng[d];
		for(int i=0;i<n;i+=m2){ll w=1;
			for(int j=0;j<m;++j){
				int &A=a[i+j+m],&B=a[i+j];ll t=w*A%P;
				A=B-t;if(A<0)A+=P;
				B+=t;if(B>=P)B-=P;
				w=w*_w%P;
			}
		}
	}
	if(!t)for(int i=0;i<n;++i)a[i]=(ll)a[i]*inv%P;
}
int main(){
	scanf("%d%d",&n,&k);
	int tt=1,rr=-1;while(tt<=n*9)tt<<=1,++rr;n/=2;inv=qk(tt,P-2);
	g[rr]=qk(G,(P-1)/tt);
	ng[rr]=qk(g[rr],P-2);
	dep(i,rr-1,0)g[i]=g[i+1]*g[i+1]%P,ng[i]=ng[i+1]*ng[i+1]%P;	
	int nn=0;while((2<<nn)<=n)++nn;
	rep(i,1,k)scanf("%d",&p[i]);
	rep(i,1,k)rep(j,1,k)++a[0][9+p[i]-p[j]];
	NTT(a[0],tt,1);
	rep(i,1,nn)rep(j,0,tt-1)a[i][j]=(ll)a[i-1][j]*a[i-1][j]%P;
	s[0]=1;NTT(s,tt,1);
	rep(i,0,nn)if(n&(1<<i))rep(j,0,tt-1)s[j]=(ll)s[j]*a[i][j]%P;
	NTT(s,tt,0);
	printf("%d\n",s[n*9]);
}