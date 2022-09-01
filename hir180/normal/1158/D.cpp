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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef pair<ll,ll> Q;
bool cmp(Q p,Q q)
{
	if(p.fi != q.fi) return p.fi < q.fi;
	return p.sc < q.sc;
}
ll det(Q a,Q b)
{
	return a.fi*b.sc - a.sc*b.fi;
}
bool ccw(P a,P b,P c)
{
	return 1LL*(b.fi-a.fi)*(c.sc-a.sc)-1LL*(b.sc-a.sc)*(c.fi-a.fi) > 0;
}
vector<Q> convex_hull(vector<Q>vs)
{
	sort(vs.begin(),vs.end(),cmp);
	int k = 0;
	vector<Q>qs (vs.size()*2);
	
	for(int i=0;i<vs.size();i++)
	{
		while(k>1 && det(mp(qs[k-1].fi-qs[k-2].fi,qs[k-1].sc-qs[k-2].sc),mp(vs[i].fi-qs[k-1].fi,vs[i].sc-qs[k-1].sc))<=0)
		{
			k--;
		}
		qs[k++] = vs[i];
	}
	for(int i=vs.size()-2,t = k;i>=0;i--)
	{
		while(k>t && det(mp(qs[k-1].fi-qs[k-2].fi,qs[k-1].sc-qs[k-2].sc),mp(vs[i].fi-qs[k-1].fi,vs[i].sc-qs[k-1].sc))<=0)
		{
			k--;
		}
		qs[k++] = vs[i];
	}
	qs.resize(k-1);
	return qs;
}
vector<Q>vec;
Q pt[3005];
bool used[3005];
int ans[3005];
int n;
map<Q,int>M;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x,y; cin>>x>>y;
		pt[i] = mp(x,y);
		vec.pb(mp(x,y));
		M[mp(x,y)] = i;
	}
	vector<Q>kaede = convex_hull(vec);
	assert(kaede.size() >= 3);
	for(int i=0;i<kaede.size();i++){
		assert(ccw(kaede[i],kaede[(i+1)%kaede.size()],kaede[(i+2)%kaede.size()]));
	}
	string str; cin>>str;
	int curr , nxt;
	if(str[0] == 'R'){
		curr = M[kaede[1]]; nxt = M[kaede[0]];
	}
	else{
		curr = M[kaede[0]]; nxt = M[kaede[1]];
	}
	used[curr] = 1;
	used[nxt] = 1;
	ans[1] = curr; ans[2] = nxt;
	for(int i=3;i<n;i++){
		int dir = (str[i-2]=='R'?1:0);
		if(dir){
			int cur = -1;
			for(int j=1;j<=n;j++){
				if(used[j]) continue;
				if(cur == -1) cur = j;
				else if(ccw(pt[nxt],pt[cur],pt[j])) cur = j;
			}
			nxt = cur;
			ans[i] = nxt;
			used[nxt] = 1;
		}
		else{
			int cur = -1;
			for(int j=1;j<=n;j++){
				if(used[j]) continue;
				if(cur == -1) cur = j;
				else if(!ccw(pt[nxt],pt[cur],pt[j])) cur = j;
			}
			nxt = cur;
			ans[i] = nxt;
			used[nxt] = 1;
		}
	}
	for(int i=1;i<=n;i++) if(!used[i]) ans[n] = i;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	for(int i=1;i<=n-2;i++){
		bool dir = (str[i-1] == 'L');
		assert(ccw(pt[ans[i]],pt[ans[i+1]],pt[ans[i+2]]) == dir);
	}
}