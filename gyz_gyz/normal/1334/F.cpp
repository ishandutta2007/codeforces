#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e18;
const int mo=998244353;
int n;ll a0;
ll a[N],p[N];int s[N],ls[N];
void f(int x,ll y){
	for(;x<=n;x+=x&-x)a[x]+=y;
}
ll q(int x){ll r=a0;
	for(;x;x-=x&-x)r+=a[x];return r;
}
int main(){int m;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&s[i]);
	rep(i,1,n)scanf("%lld",&p[i]);
	scanf("%d",&m);int LS=0;
	rep(i,0,n)ls[i]=-1;
	rep(i,1,m){int x;
		scanf("%d",&x);
		ls[x]=LS;LS=x;
	}
	f(1,inf);
	rep(i,1,n){ll res;
		if(~ls[s[i]])res=q(ls[s[i]]);
		a0+=p[i];
		if(p[i]>0)f(s[i],-p[i]);
		if(~ls[s[i]]){
			ll nw=q(s[i]);
			if(res<nw){
				f(s[i],res-nw);
				if(s[i]<n)f(s[i]+1,nw-res);
			}
		}
	}
	ll ans=q(LS);
	if(ans>=inf/2)printf("NO\n");
	else printf("YES\n%lld\n",ans);
}