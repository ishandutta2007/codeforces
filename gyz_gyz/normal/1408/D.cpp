#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e3+10;
const int mo=1e9+7;
const ll inf=1e18;
int a[N],b[N],c[N],d[N];multiset<int>s;
struct pr{
	int t,x;
	friend bool operator<(const pr&a,const pr&b){return a.t<b.t;};
};
vector<pr>p;
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]);
	rep(i,1,m)scanf("%d%d",&c[i],&d[i]);
	s.insert(0);
	rep(i,1,n)rep(j,1,m)if(a[i]<=c[j]&&b[i]<=d[j]){
		s.insert(d[j]-b[i]+1);
		p.push_back({c[j]-a[i]+1,d[j]-b[i]+1});
	}
	int ans=*s.rbegin();
	if(!p.empty())sort(p.begin(),p.end());
	for(auto&i:p){
		s.erase(s.find(i.x));
		ans=min(ans,i.t+*s.rbegin());
	}
	printf("%d\n",ans);
}