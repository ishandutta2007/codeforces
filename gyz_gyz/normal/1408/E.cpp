#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
const ll inf=1e18;
int f[N];ll a[N];
struct pr{
	int x,y;ll z;
	friend bool operator<(const pr&a,const pr&b){return a.z>b.z;}
};
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
vector<pr>p;
int main(){int m,n;ll ans=0;
	scanf("%d%d",&m,&n);
	rep(i,1,m+n){
		scanf("%lld",&a[i]);
		f[i]=i;
	}
	rep(i,1,m){int s;
		scanf("%d",&s);
		rep(j,1,s){int x;
			scanf("%d",&x);
			ll v=a[i]+a[m+x];ans+=v;
			p.push_back({i,m+x,v});
		}
	}
	if(!p.empty())sort(p.begin(),p.end());
	for(auto&i:p){
		int x=gf(i.x),y=gf(i.y);
		if(x!=y){
			ans-=i.z;f[y]=x;
		}
	}
	printf("%lld\n",ans);
}