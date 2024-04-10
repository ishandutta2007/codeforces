/*
 



















 
 */
#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
const int INF = 1000 * 1000 * 1000 + 228;
const string FILENAME = "input";
const int MAXN = 5201;
//WULD NAH KEST!!!

struct point
{
	int x, y; 
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

inline point operator -(const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}


inline long long vec(const point &a, const point &b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}


inline bool operator ==(const point &a, const point &b) {
	return a.x == b.x && a.y == b.y;
}

inline bool operator <(const point &a, const point &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}


int n;
point p[MAXN];
vector<long long> cnt[MAXN];
unordered_map<long long, bool> used;


int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	n *= 2;
	int shift = 1000001;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		long long hash = 1LL * (p[i].x + shift) * (2 * shift + 2) + p[i].y + shift;
		used[hash] = true;
	}
	random_shuffle(p, p + n);
	for (int i = 0; i < n; i++) {
		cnt[i].resize(n - 1);
		int ft = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				point ts = p[j] - p[i];
				if (ts.x < 0) {
					ts.x *= -1;
					ts.y *= -1;
				} else if (ts.x == 0 && ts.y < 0) {
					ts.y *= -1;
				}
				if (ts.x == 0) {
					ts.y = 1;
				} else {
					if (ts.y == 0) {
						ts.x = 1;
					} else {
						int f = __gcd(abs(ts.x), abs(ts.y));
						ts.x /= f;
						ts.y /= f;
					}
				}
				long long hash = 1LL * (ts.x + shift) * (2 * shift + 2) + ts.y + shift;
				cnt[i][ft] = hash;
				ft++;
			}
		}
		sort(all(cnt[i]));
		int l = 0;
		vector<long long> st;
		while (l < sz(cnt[i])) {
			int r = l;
			while (r + 1 < sz(cnt[i]) && cnt[i][r + 1] == cnt[i][l]) {
				r++;
			}
			if (l != r) {
				l = r + 1;
			} else {
				st.push_back(cnt[i][l]);
				l++;
			}
		}
		cnt[i] = st;
	}
	for (int i = 1; i < n; i++) {
		int j = 1;
		if (i == 1) {
			j++;
		}	
		point ts = p[i] - p[0];
		if (ts.x == 0) {
			ts.y = 1;
		} else {
			if (ts.y == 0) {
				ts.x = 1;
			} else {
				if (ts.x < 0) {
					ts.x *= -1;
					ts.y *= -1;
				}
				int f = __gcd(abs(ts.x), abs(ts.y));
				ts.x /= f;
				ts.y /= f;
			}
		}
		long long hash = 1LL * (ts.x + shift) * (2 * shift + 2) + ts.y + shift;
		int fs = lower_bound(all(cnt[0]), hash) - cnt[0].begin();
		if (fs == sz(cnt[0]) || cnt[0][fs] != hash){continue;}
		for (int k = j + 1; k < n; k++) {
			if (k == i) {
				continue;
			}
			//0 - i
			//j - k;
			long long a = p[i].y - p[0].y;
			long long b = p[0].x - p[i].x;
			long long c = a * p[0].x + b * p[0].y;
			long long a1 = p[k].y - p[j].y;
			long long b1 = p[j].x - p[k].x;
			long long c1 = a1 * p[j].x + b1 * p[j].y;
			if ((b * a1 - b1 * a) == 0 || (c * a1 - c1 * a) % (b * a1 - b1 * a) != 0 || ((c * b1 - c1 * b)) % (b * a1 - b1 * a) != 0) continue;
			long long y = (c * a1 - c1 * a) / (b * a1 - b1 * a);
			long long x = (c * b1 - c1 * b) / (a * b1 - a1 * b);
			if (abs(x) > 1000000 || abs(y) > 1000000) {
				continue;
			}
			point lune = point(x, y);
			long long hash1 = 1LL * (lune.x + shift) * (2 * shift + 2) + lune.y + shift;
			if (used.find(hash1) != used.end()) {
				continue;
			}
			used[hash1] = true;
			point ts = p[k] - p[j];
			if (ts.x == 0) {
				ts.y = 1;
			} else {
				if (ts.y == 0) {
					ts.x = 1;
				} else {
					if (ts.x < 0) {
						ts.x *= -1;
						ts.y *= -1;
					}
					int f = __gcd(abs(ts.x), abs(ts.y));
					ts.x /= f;
					ts.y /= f;
				}
			}
			long long hash = 1LL * (ts.x + shift) * (2 * shift + 2) + ts.y + shift;
			int fs = lower_bound(all(cnt[j]), hash) - cnt[j].begin();
			if (fs == sz(cnt[j]) || cnt[j][fs] != hash){continue;}
			bool bad = false;
			for (int t = 1; t < n; t++) {
				if (t == i || t == j || t == k) {
					continue;
				}
				point ts = lune - p[t];
				if (ts.x == 0) {
					ts.y = 1;
				} else {
					if (ts.y == 0) {
						ts.x = 1;
					} else {
						if (ts.x < 0) {
							ts.x *= -1;
							ts.y *= -1;
						}
						int f = __gcd(abs(ts.x), abs(ts.y));
						ts.x /= f;
						ts.y /= f;
					}
				}
				long long hash = 1LL * (ts.x + shift) * (2 * shift + 2) + ts.y + shift;
				int fs = lower_bound(all(cnt[t]), hash) - cnt[t].begin();
				if (fs == sz(cnt[t]) || cnt[t][fs] != hash) {
					bad = true; 
					break;
				}
			}
			if (!bad) {
				cout << "Yes\n";
				cout << lune.x << ' ' << lune.y << endl;
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}