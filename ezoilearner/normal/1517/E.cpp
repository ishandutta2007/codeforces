#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<ll,ll> pii;
#define FR first
#define SE second

inline void rd(ll &x){
	x=0;char ch=getchar();ll f=1;
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

ll n;
#define Maxn 200010
ll a[Maxn];
ll sum[Maxn];
ll pf[Maxn];

ll c[Maxn<<1];ll cnt=0;

ll b[2][Maxn<<1];
ll lowbit(ll x){return x&(-x);}
void Add(ll ty,ll v){
	ll p=lower_bound(c+1,c+cnt+1,v)-c;
	for(ll i=p;i<=cnt;i+=lowbit(i))b[ty][i]++;
}

ll query(ll ty,ll x){
	ll res=0;
	for(ll i=x;i;i-=lowbit(i))res+=b[ty][i];
	return res;
}

int main(){
	ll T;rd(T);
	while(T--){
	rd(n);cnt=0;
	rep(i,1,n){
		rd(a[i]);
		sum[i]=a[i]-sum[i-1];
		pf[i]=pf[i-1]+a[i];
	}
	if(n==1){
		puts("1");
		continue;
	}
	ll ans=1;
	if(pf[n]-pf[1]>a[1])ans++;
	if(pf[n-1]-pf[1]>a[1]+a[n]&&n>=4)ans++;
	rep(i,2,n){
		c[++cnt]=-sum[i-1]-pf[i-1];
		c[++cnt]=-sum[i-1]-(pf[i-1]-pf[1])+a[1];
	}
	c[++cnt]=0;
	sort(c+1,c+cnt+1);
	cnt=unique(c+1,c+cnt+1)-c-1; 
	rep(i,1,cnt)b[0][i]=b[1][i]=0;
	Add(0,0);
	rep(i,2,n){
		ll at=(i%2)^1;
		Add(at,-sum[i-1]-pf[i-1]);
		Add(at,-sum[i-1]-(pf[i-1]-pf[1])+a[1]);
		ll tmp=pf[n]-pf[i]-sum[i];
		ll z=upper_bound(c+1,c+cnt+1,-tmp)-c;
		ans+=query(at,cnt)-query(at,z-1); 
		if(n-i>=3){
			tmp=pf[n-1]-pf[i]-a[n]-sum[i];
			//>-tmp
			ll z=upper_bound(c+1,c+cnt+1,-tmp)-c;
			ans+=query(at,cnt)-query(at,z-1);
		}
	}
	rep(i,2,n-1)
		if(pf[i]>pf[n]-pf[i])ans++;
	printf("%d\n",ans%998244353);
}
	return 0;
}