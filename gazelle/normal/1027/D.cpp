#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> c(n);
	REP(i,n) cin>>c[i];
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	REP(i,n) a[i]--;
	ll ans=0;
	vector<set<ll>> in_edg(n);
	vector<set<ll>> out_edg(n);
	REP(i,n) {
		out_edg[i].insert(a[i]);
		in_edg[a[i]].insert(i);
	}
	vector<bool> used(n,false);
	queue<ll> q;
	REP(i,n) if(in_edg[i].size()==0) {
		q.push(i);
	}
	while(!q.empty()) {
		ll p=q.front();
		q.pop();
		used[p]=true;
		for(auto x: out_edg[p]) {
			in_edg[x].erase(p);
			if(in_edg[x].size()==0) q.push(x);
		}
	}
	REP(i,n) if(!used[i]) {
		ll tmp=c[i];
		used[i]=true;
		ll pos=a[i];
		while(!used[pos]) {
			tmp=min(tmp,c[pos]);
			used[pos]=true;
			pos=a[pos];
		}
		ans+=tmp;
	}
	cout<<ans<<endl;
}