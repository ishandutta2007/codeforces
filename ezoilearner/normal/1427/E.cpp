#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pair<ll,ll>,bool> pllb;
ll n;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second

pllb seq[Maxn];int cnt=0;
void F(ll x,ll y,bool tp){
	seq[++cnt]=pllb(pll(x,y),tp);
}

void Fast_Pow(ll a,ll b){
	ll res=0;
	while(b){
		if(b&1)F(res,a,1),res+=a;
		F(a,a,1);
		a*=2;
		b>>=1;
	}
}

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

int main(){
	scanf("%lld",&n);
	ll t=0;
	F(n,n,0);
	while(n>=(1ll<<(t+1)))t++;
	ll tmp=n;
	for(int i=0;i<t;++i){
		F(tmp,tmp,1);
		tmp*=2;
	}
	F(n,tmp,0);
	ll x=n,y=(n^tmp);//y odd
	F(x,x,1);
	x<<=1;
	for(int i=1;i<x;++i)
		if((y*i)%x==1){
			Fast_Pow(y,i);
			Fast_Pow(x,(y*i-1)/x);
			F(y*i,y*i-1,0);
			break;
		}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
		if(seq[i].SE)printf("%lld + %lld\n",seq[i].FR.FR,seq[i].FR.SE);
		else printf("%lld ^ %lld\n",seq[i].FR.FR,seq[i].FR.SE);
	return 0;
}