#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n,m,p;
#define Maxn 200010
ll a[Maxn];

mt19937 mt_rand(time(0));

typedef pair<int,ll> pil;

map<ll,int> mp;

char S[65];

int cnt;
int to[20];
ll num[1<<15];
int F[1<<15];

void FWT(){
	for(int i=1;i<(1<<cnt);i<<=1)
		for(int j=0;j<(1<<cnt);j+=i<<1)
			for(int k=0;k<i;++k)F[j+k]+=F[j+k+i];
}

int all[1<<15];
int lowbit(int x){return x&(-x);}

int main(){
	rd(n);rd(m);rd(p);
	pil res=make_pair(0,0ll);
	for(int i=1;i<(1<<p);++i)all[i]=all[i^lowbit(i)]+1;
	rep(i,1,n){
		scanf("%s",S);
		rep(j,0,m-1)
			if(S[j]=='1')a[i]|=(1ll<<j);
	}
	for(int T=30;T>=1;--T){
		memset(F,0,sizeof(int)*(1<<p));
		mp.clear();
		int x=1ull*mt_rand()*mt_rand()%n+1;
		cnt=0;
		rep(j,0,m-1)
			if(a[x]&(1ll<<j))to[cnt++]=j;
		for(int i=0;i<(1<<cnt);++i){
			ll sta=0;
			for(int j=0;j<cnt;++j)
				if(i&(1<<j))sta|=(1ll<<to[j]);
			mp[sta]=i;num[i]=sta;
		}
		rep(i,1,n)
			F[mp[a[i]&a[x]]]++;
		FWT();
		for(int i=0;i<(1<<cnt);++i)
			if(F[i]>=(n+1)/2){
				res=max(res,pil(all[i],num[i]));
			}
	}
	rep(j,0,m-1)
		if(res.SE&(1ll<<j))putchar('1');
		else putchar('0');puts("");
	return 0;
}