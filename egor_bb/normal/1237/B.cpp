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

int a[N], b[N], posB[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    forn(i, n) {
		cin >> a[i];
	}
	forn(i, n) {
		cin >> b[i];
		posB[b[i]] = i;
	}
	set<int> posGot;
	int ans = 0;
	forn(i, n) {
		if (posGot.upper_bound(posB[a[i]]) != posGot.end()) {
			ans++;
		}
		posGot.insert(posB[a[i]]);
	}
	cout << ans << '\n';
    return 0;
}