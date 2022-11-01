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
	int n, m;
	cin>>n>>m;
	vector<int> p(n);
	REP(i, n) {
		cin>>p[i];
	}
	REP(i, m) {
		int l, r, x;
		cin>>l>>r>>x;
		--l;
		--r;
		--x;
		if(l <= x && x <= r) {
			int cnt = 0;
			FOR(i, l, r + 1) {
				if(p[i] < p[x]) ++cnt;
			}
			if(l + cnt == x) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		} else {
			cout<<"Yes"<<endl;
		}
	}
}