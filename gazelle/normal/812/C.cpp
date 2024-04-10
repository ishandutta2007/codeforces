#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ll n, S;
	cin>>n>>S;
	vector<ll> a(n);
	REP(i, n) cin>>a[i];
	ll lb = 0, ub = n + 1;
	while(ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		vector<ll> c(n);
		REP(i, n) {
			c[i] = a[i] + (i + 1) * mid;
		}
		sort(ALL(c));
		ll sum = 0;
		REP(i, mid) {
			sum += c[i];
		}
		if(sum <= S) lb = mid;
		else ub = mid;
	}
	ll res = 0;
	vector<ll> c(n);
	REP(i, n) c[i] = a[i] + (i + 1) * lb;
	sort(ALL(c));
	REP(i, lb) {
		res += c[i];
	}
	cout<<lb<<" "<<res<<endl;
}