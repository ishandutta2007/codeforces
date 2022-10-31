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

ll compute(int x, int split) {
	ll ans = 0;
	int cntLarge = x % split;
	int cntSmall = split - cntLarge;
	int len = x / split;
	ans += cntSmall * (len * 1ll * len);
	ans += cntLarge * ((len + 1) * 1ll * (len + 1));
	return ans;
}

int a[N], split[N];
ll curValue[N], nextValue[N];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	set<pair<pair<ll, ll>, int>> s;
	forn(i, n) {
		cin >> a[i];
		split[i] = 1;
		curValue[i] = compute(a[i], split[i]);
		if (a[i] > split[i]) {
			nextValue[i] = compute(a[i], split[i] + 1);
			s.insert(mp(mp(nextValue[i] - curValue[i], -a[i]), i));
		}
	}
	int nInit = n;
	while(n < k) {
		n++;
		int ind = s.begin()->snd;
//		cerr << ind << '\n';
		s.erase(s.begin());
		split[ind]++;
		curValue[ind] = nextValue[ind];
		if (a[ind] > split[ind]) {
			nextValue[ind] = compute(a[ind], split[ind] + 1);
			s.insert(mp(mp(nextValue[ind] - curValue[ind], -a[ind]), ind));
		}
	}
	ll ans = 0;
	forn(i, nInit) {
		ans += curValue[i];
	}
	cout << ans << '\n';
	
    return 0;
}