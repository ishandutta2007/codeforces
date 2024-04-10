#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main(void) {
	string s;
	cin>>s;
	ll cntb = 0;
	ll ans = 0;
	for(ll i = s.size() - 1; i >= 0; --i) {
		if(s[i] == 'a' && cntb > 0) {
			ans += cntb;
			ans = ans % MOD;
			cntb *= 2;
			cntb = cntb % MOD;
		} else if(s[i] == 'b') ++cntb;
	}
	cout<<ans<<endl;
}