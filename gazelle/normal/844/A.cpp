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
#include<unordered_map>

#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	vector<int> cnt(26,0);
	REP(i,s.size()) ++cnt[s[i]-'a'];
	int k;
	cin>>k;
	int c=0;
	int buf=0;
	REP(i,26) {
		if(cnt[i]>0) ++c;
		if(cnt[i]>1) buf+=cnt[i]-1;
	}
	if(c>=k) cout<<0<<endl;
	else {
		if(buf>=k-c) cout<<k-c<<endl;
		else cout<<"impossible"<<endl;
	}
}