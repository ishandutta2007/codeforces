#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<string> s(n);
	vector<pair<string,string>> lr(n);
	vector<vector<set<string>>> kn(n,vector<set<string>>(12));
	REP(i,n) cin>>s[i];
	REP(i,n) {
		if(s[i].size()<12) {
			lr[i].first=s[i];
			lr[i].second=s[i];
		} else {
			lr[i].first=s[i].substr(0,12);
			lr[i].second=s[i].substr(s[i].size()-12,12);
		}
	}
	REP(i,n) {
		REP(j,12) {
			REP(k,(ll)s[i].size()-(j+1)+1) {
				kn[i][j].insert(s[i].substr(k,j+1));
			}
		}
	}
	ll m;
	cin>>m;
	REP(i,m) {
		ll a,b;
		cin>>a>>b;
		--a;
		--b;
		vector<set<string>> ss(12);
		REP(j,12) {
			auto ite=kn[a][j].begin();
			while(ite!=kn[a][j].end()) {
				ss[j].insert(*ite);
				++ite;
			}
			ite=kn[b][j].begin();
			while(ite!=kn[b][j].end()) {
				ss[j].insert(*ite);
				++ite;
			}
		}
		string merg=lr[a].second+lr[b].first;
		REP(j,12) {
			REP(k,(ll)merg.size()-(j+1)+1) {
				ss[j].insert(merg.substr(k,j+1));
			}
		}
		pair<string,string> tg;
		if((ll)((lr[a].first).size())==12) {
			tg.first=lr[a].first;
		} else {
			string hoge=lr[a].first+lr[b].first;
			if((ll)hoge.size()>12) tg.first=hoge.substr(0,12);
			else tg.first=hoge;
		}
		if((ll)((lr[b].second).size())==12) {
			tg.second=lr[b].second;
		} else {
			string hoge=lr[a].second+lr[b].second;
			if((ll)hoge.size()>12) tg.second=hoge.substr((ll)hoge.size()-12,12);
			else tg.second=hoge;
		}
		lr.pb(tg);
		kn.pb(ss);
		ll res=0;
		REP(j,12) {
			if((ll)ss[j].size()==(1ll<<(j+1))) res=j+1;
		}
		cout<<res<<endl;
	}
}