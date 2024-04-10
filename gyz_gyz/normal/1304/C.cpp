#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int mo=1e9+7;
const int inf=1e9;
struct pr{ll t,l,r;
	friend bool operator<(const pr&a,const pr&b){return a.t<b.t;}
}a[N];
void sol(){int n;ll m;
	scanf("%d%lld",&n,&m);
	ll l=m,r=m,nw=0;
	rep(i,1,n)scanf("%lld%lld%lld",&a[i].t,&a[i].l,&a[i].r);
	sort(a+1,a+n+1);
	rep(i,1,n){
		l-=a[i].t-nw;r+=a[i].t-nw;nw=a[i].t;
		l=max(l,a[i].l);r=min(r,a[i].r);
		if(l>r){
			printf("NO\n");return;
		}
	}
	printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}