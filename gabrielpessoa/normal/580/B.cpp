#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<ll, ll> llp;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

llp m[SIZE];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++) {
		scanf("%lld %lld", &m[i].first, &m[i].second);
	}
	sort(m, m+n);
	int l = 0, r = 0;
	ll curFriendship = 0, best = 0;
	while(r < n) {
		if(m[r].first < m[l].first + d) {
			curFriendship += m[r++].second;
			best = max(best, curFriendship);
		} else {
			curFriendship -= m[l++].second;
		}
	}
	printf("%lld\n", best);
	return 0;
}