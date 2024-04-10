#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 2e5 + 100;
const int REPS = 30;
const int MAX_MASK = 1 << 15;

ll initMasks[N], masks[N];
int cnt[MAX_MASK];
vector<int> inds[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	srand(time(0));
	int n, m, p;
	cin >> n >> m >> p;
	forn(i, n) {
		string s;
		cin >> s;
		forn(j, m) {
			if (s[j] == '1') {
				initMasks[i] |= 1ll << j;
				inds[i].pb(j);
			}
		}
	}
	int ans = 0;
	ll maskAns = 0;
	forn(rep, REPS) {
		int randP = abs((rand() << 15) ^ rand()) % n;
		int maxBits = sz(inds[randP]);
		if (maxBits < ans) continue;
		forn(i, n) {
			masks[i] = 0;
			forn(j, sz(inds[randP])) {
				int ind = inds[randP][j];
				if (initMasks[i] & (1ll << ind)) {
					masks[i] |= 1ll << j;
				}
			}
		}
		forn(i, 1 << maxBits) {
			cnt[i] = 0;
		}
		forn(i, n) {
			cnt[masks[i]]++;
		}
		forn(mask, 1 << maxBits) {
			for (int upperMask = mask; upperMask < (1 << maxBits); upperMask = (upperMask + 1) | mask) {
				if (upperMask != mask) {
					cnt[mask] += cnt[upperMask];
				}
			}
		}
		ll localMask = 0;
		int localAns = 0;
		forn(i, 1 << maxBits) {
			if (cnt[i] * 2 >= n) {
				int bitsCnt = __builtin_popcount(i);
				if (bitsCnt > localAns) {
					localMask = i;
					localAns = bitsCnt;
				}
			}
		}
		if (localAns > ans) {
			ans = localAns;
			maskAns = 0;
			forn(j, sz(inds[randP])) {
				int ind = inds[randP][j];
				if (localMask & (1ll << j)) {
					maskAns |= 1ll << ind;
				}
			}
		}
	}
	forn(i, m) {
		cout << ((maskAns >> i) & 1);
	}
	cout << '\n';
	return 0;
}