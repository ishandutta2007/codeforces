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
#include<complex>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	int n, k, q;
	cin>>n>>k>>q;
	vector<int> t(200001, 0);
	REP(i, n) {
		int l, r;
		cin>>l>>r;
		++t[l];
		if(r + 1 < 200001) --t[r + 1];
	}
	FOR(i, 1, 200001) {
		t[i] += t[i - 1];
	}
	REP(i, 200001) {
		if(t[i] >= k) t[i] = 1;
		else t[i] = 0;
	}
	vector<int> wa(200001, 0);
	FOR(i, 1, 200001) {
		wa[i] = t[i] + wa[i - 1];
	}
	REP(i, q) {
		int a, b;
		cin>>a>>b;
		cout<<wa[b] - wa[a - 1]<<endl;
	}
}