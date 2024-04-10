#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 100;

int l[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	forn(i, m) {
		cin >> l[i];
		if (i + l[i] > n) {
			cout << -1 << '\n';
			return 0;
		}
		sum += l[i];
	}
	if (sum < n) {
		cout << -1 << '\n';
		return 0;
	}
	int curPos = n;
	fornr(i, m) {
		int minPos = curPos - l[i];
		int maxPos = i;
		ans[i] = max(minPos, maxPos);
		curPos = ans[i];
	}
	forn(i, m) {
		cout << ans[i] + 1 << " ";
	}
	cout << '\n';
	
    return 0;
}