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
#include<complex>

#define INF (long long)1000000000
#define MOD 1000000007
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

vector<vector<int> > l;

ld dfs(ll p, ll b) {
	if(b==-1) {
		ld res=0;
		REP(i,l[p].size()) {
			res+=dfs(l[p][i],p)/(ld)l[p].size();
		}
		return res;
	} else {
		ld res=0;
		REP(i,l[p].size()) {
			if(l[p][i]==b) continue;
			else {
				res+=dfs(l[p][i],p)/(ld)(l[p].size()-1);
			}
		}
		return res+1;
	}
}

int main() {
	int n;
	cin>>n;
	l.resize(n);
	REP(i,n-1) {
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		l[a].pb(b);
		l[b].pb(a);
	}
	cout<<fixed<<showpoint<<setprecision(13)<<dfs(0,-1)<<endl;
}