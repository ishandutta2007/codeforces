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
#define EPS 1e-8
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
	REP(i,n) cin>>s[i];
	map<string,vector<ll> > se;
	REP(i,n) {
		vector<string> ss(45);
		int c=0;
		REP(j,9) {
			FOR(k,j,9) {
				ss[c]=s[i].substr(j,k-j+1);
				++c;
			}
		}
		sort(ALL(ss));
		ss.erase(unique(ALL(ss)),ss.end());
		REP(j,ss.size()) {
			se[ss[j]].pb(i);
		}
	}
	vector<string> res(n);
	REP(i,n) res[i]=s[i];
	auto ite=se.begin();
	while(ite!=se.end()) {
		string t=(*ite).first;
		vector<ll> vec=(*ite).second;
		if(vec.size()==1) {
			if(res[vec[0]].size()>t.size()) {
				res[vec[0]]=t;
			}
		}
		++ite;
	}
	REP(i,n) cout<<res[i]<<endl;
}