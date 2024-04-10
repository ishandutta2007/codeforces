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

const int K = 10;
const int N = 2005;

string maskStrings[K] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int masks[K];
int a[N];
int dp[N][N];


int toMask(string &s) {
	int res = 0;
	forn(t, 7) {
		if (s[t] == '1') {
			res |= (1 << t);
		}
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	forn(i, K) {
		masks[i] = toMask(maskStrings[i]);
	}
	int n, k;
	cin >> n >> k;
	forn(i, n) {
		string s;
		cin >> s;
		a[i] = toMask(s);
	}
	dp[n][0] = 1;
	fornr(i, n) {
		vector<int> can;
		forn(j, K) {
			if ((a[i] & masks[j]) == a[i]) {
				can.pb(__builtin_popcount(masks[j] ^ a[i]));
			}
		}
		forn(light, k + 1) {
			if (!dp[i + 1][light]) continue;
			for(int t : can) {
				if (light + t <= k) {
					dp[i][light + t] = 1;
				}
			}
		}
	}
	if (!dp[0][k]) {
		cout << -1 << '\n';
		return 0;
	}
	int cur = k;
	forn(i, n) {
		fornr(j, K) {
			if ((a[i] & masks[j]) == a[i]) {
				int t = __builtin_popcount(masks[j] ^ a[i]);
				if (cur - t >= 0 && dp[i + 1][cur - t]) {
					cout << j;
					cur -= t;
					break;
				}
			}
		}
	}
	cout << '\n';
    return 0;
}