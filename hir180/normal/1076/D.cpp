#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll d[300005];
int n,m,k;
vector<pair<int,pair<int,ll> > >edge[300005];
int in[300005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge[a].pb(mp(i,mp(b,1LL*c)));
		edge[b].pb(mp(i,mp(a,1LL*c)));
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
	que.push(mp(0,1));
	rep(i,300005) d[i] = 1e18;
	d[1] = 0;
	while(!que.empty()){
		pair<ll,int>p = que.top(); que.pop();
		if(d[p.sc] != p.fi) continue;
		rep(i,edge[p.sc].size()){
			int to = edge[p.sc][i].sc.fi;
			ll cs = edge[p.sc][i].sc.sc;
			if(d[to] > d[p.sc]+cs){
				d[to] = d[p.sc]+cs;
				que.push(mp(d[to],to));
				in[to] = edge[p.sc][i].fi;
			}
		}
	}
	vector<pair<ll,int> >vec;
	for(int i=2;i<=n;i++) vec.pb(mp(d[i],in[i]));
	SORT(vec);
	vector<int>ans;
	for(int i=0;i<vec.size();i++){
		if(i == k) break;
		ans.pb(vec[i].sc);
	}
	cout << ans.size() << endl;
	rep(i,ans.size()) printf("%d ",1+ans[i]);
	puts("");
}