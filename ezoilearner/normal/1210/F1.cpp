#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

const int Mod=1000000007;
int I100;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			a=1ll*a*a%Mod;
			b>>=1;
		}
		return res;
	}
}using namespace modular;

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();		
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n,L;
#define Maxn 8
#define Maxs 128
#define Maxz 40010

int lowbit(int x){return x&(-x);}
int to[Maxs];

int hh[Maxn],id[Maxs],rid[Maxn][40];
int p[Maxn][Maxn],P[Maxn][Maxs];
void init(int *q,int *S){
	for(int i=0;i<(1<<n);++i){
		S[i]=1;
		for(int j=0;j<n;++j)
			if(i&(1<<j))S[i]=mul(S[i],q[j]);
			else S[i]=mul(S[i],dec(1,q[j]));
	}
}

ll p1[Maxz];int p2[Maxz];int len;
namespace Hs{
	const int mod=1e7+7;
	int head[mod],val[Maxz],nxt[Maxz],tot=0;
	ll num[Maxz];
	void init(){
		rep(i,1,tot)head[num[i]%mod]=0;
		tot=0;
	}
	void Add(ll x,int y){
		int key=x%mod;
		for(int i=head[key];i;i=nxt[i])
			if(num[i]==x){
				val[i]=add(val[i],y);
				return;
			}
		tot++;num[tot]=x;val[tot]=y;nxt[tot]=head[key];head[key]=tot;
	}
	void copy(){
		len=tot;rep(i,1,len)p1[i]=num[i],p2[i]=val[i];
	}
	void report(){
		rep(i,1,tot)
			if(num[i]==1){
				printf("%d\n",val[i]);
				return;
			}
	}
}

ll bon[Maxn];
ll sta[Maxs];
void calc(int u,ll q,int x){
	rep(i,0,n-1)bon[i]=0ll;
	rep(i,0,hh[u+1]-1){
		int p=rid[u+1][i],_p=p;
		while(p){
			int l=to[lowbit(p)];
			if(q&(1ll<<id[_p^(1<<l)]))bon[l]|=(1ll<<i);
			p^=(1<<l);
		}
	}
	for(int i=1;i<L;++i)sta[i]=sta[i^lowbit(i)]|bon[to[lowbit(i)]];
	for(int i=0;i<(1<<n);++i)
		Hs::Add(sta[i],mul(P[u+1][i],x));
}

int main(){
	I100=Fast_Pow(100,Mod-2);rd(n);L=(1<<n);
	rep(i,0,n-1)to[1<<i]=i;
	rep(i,1,n)rep(j,0,n-1){
		rd(p[i][j]);
		p[i][j]=mul(p[i][j],I100);
	}
	rep(i,1,n)init(p[i],P[i]);
	for(int i=0;i<(1<<n);++i){
		int z=0;
		for(int j=0;j<n;++j)
			if(i&(1<<j))z++;
		id[i]=hh[z];rid[z][hh[z]]=i;hh[z]++;
	}
	Hs::Add(1,1);
	rep(u,0,n-1){
		len=0;
		Hs::copy();Hs::init();
		rep(i,1,len)calc(u,p1[i],p2[i]);
	}
	Hs::report();
	return 0;
}