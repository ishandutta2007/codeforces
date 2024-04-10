#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=5e5+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int a[N],v[N],l[N],r[N];
int main(){int n,k;
	set<pair<int,int>>s;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);
		l[i]=i-1;if(i<n)r[i]=i+1;
		s.insert({n-a[i],i});
	}int t=2;
	while(!s.empty()){t=3-t;
		int x=s.begin()->sc;
		v[x]=t;s.erase(s.begin());
		rep(i,1,k){
			if(!r[x])break;
			v[r[x]]=t;
			s.erase({n-a[r[x]],r[x]});
			l[r[r[x]]]=x;
			r[x]=r[r[x]];
		}
		rep(i,1,k){
			if(!l[x])break;
			v[l[x]]=t;
			s.erase({n-a[l[x]],l[x]});
			r[l[l[x]]]=x;
			l[x]=l[l[x]];
		}
		r[l[x]]=r[x];
		l[r[x]]=l[x];
	}
	rep(i,1,n)printf("%d",v[i]);
}