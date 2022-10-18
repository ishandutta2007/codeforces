#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
2 1 1
2 2
2 2
*/
/*input
3 3 3
5 4
12 11
9 8
*/
/*input
5 10 10
22 23
17 19
13 17
8 12
2 6
*/
const int maxn = 5000;
pair<pair<int, int>, int> v[maxn];

int din[maxn] = {};
int kr[maxn];

vector<int> t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < n; ++i) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}

	sort(v, v + n);

	int pos = -1;

	for (int i = 0; i < n; ++i) {
		if (v[i].first.first > a and v[i].first.second > b) {
			din[i] = 1;
			kr[i] = -1;
		}else{
			din[i] = -10000000;
		}

		for (int j = 0; j < i; ++j) {
			if (v[i].first.first > v[j].first.first and v[i].first.second > v[j].first.second and din[j] + 1 > din[i]) {
				din[i] = din[j] + 1;
				kr[i] = j;
			}
		}

		if (din[i] > 0 and (pos == -1 or din[i] > din[pos])) {
			pos = i;
		}
	}

	while (pos >= 0) {
		t.push_back(v[pos].second);
		pos = kr[pos];
	}

	cout << t.size() << "\n";
	reverse(t.begin(), t.end());

	for (auto &&x : t) {
		cout << x + 1 << " ";
	}
}