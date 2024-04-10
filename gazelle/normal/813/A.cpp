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
	int n;
	cin>>n;
	vector<int> a(n);
	ll sum = 0;
	REP(i, n) {
		cin>>a[i];
		sum += a[i];
	}
	int m;
	cin>>m;
	bool d = false;
	ll res = 0;
	REP(i, m) {
		int l, r;
		cin>>l>>r;
		if(sum <= r) {
			d = true;
			res = max((ll)l, sum);
			break;
		}
	}
	if(d) cout<<res<<endl;
	else cout<<-1<<endl;

}