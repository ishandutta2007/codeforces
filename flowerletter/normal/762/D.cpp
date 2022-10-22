#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e5;
const int maxm = 3;
const int maxs = (1 << 8) - 1;
const ll inf = 1e18;
int n, m, a[maxn + 5][maxm + 5];
int match[maxs + 5][maxm + 5], vis[maxs + 5];
unordered_map<int, ll> f, g;
// 0, 1, 2, 3
inline int bit(int s, int k) {return s >> 2 * (k - 1) & 3;}
void init(int s) {
	static int stk[maxm + 5], tp = 0;
//	assert(!tp);
	rep(i, 1, m + 1) {
		int x = bit(s, i);
		if(x == 1) stk[++ tp] = i;
		else if(x == 2) {
			match[s][match[s][stk[tp]] = i] = stk[tp];
			tp --;
		}
	}
	vis[s] = 1;
}
int mat(int s, int k) {
	if(!vis[s]) init(s);
//	assert(bit(s, k) == 1 || bit(s, k) == 2);
//	if(!match[s][k]) {
//		cout << s << ' ' << k << '\n';
//		rep(i, 1, m + 1) cout << bit(s, i) << ' '; 
//		exit(0);
//	}
//	assert(match[s][k]);
//	assert(bit(s, k) != bit(s, match[s][k]));
	return match[s][k] - 1;
}
int main() {
	//freopen("in.txt", "r", stdin);
	n = read(), m = 3;
	rep(i, 1, m) rep(j, 1, n) a[j][i] = read();
	f[3] = a[1][1], f[3 << 2] = a[1][1];
	rep(i, 1, n) {
		if(i != 1) {
			g.clear();
			for(auto x : f) {
				int s = x.fi; ll v = x.se;
				if(bit(s, m + 1)) continue;
//				assert(!g.count(s << 2));
				g[s << 2] = v;
			}
			swap(f, g);
		}
		rep(j, 1 + (i == 1), m) {
			g.clear();
			for(auto x : f) {
				int s = x.fi; ll v = x.se;
				int l = bit(s, j), r = bit(s, j + 1);
				auto insert = [&] (int _s, ll k) {
//					int cnt = 0;
//					rep(i, 1, m + 1) if(bit(_s, i) == 1) cnt ++; else if(bit(_s, i) == 2) cnt --; 
//					if(cnt != 0){
//						cout << i << ' ' << j << ' ' << _s << ' ' << k << ' ' << l << ' ' << r << ' ' << s << '\n';;
//						rep(i, 1, m + 1) cout << bit(_s, i) << ' '; cout << '\n';
//						rep(i, 1, m + 1) cout << bit(s, i) << ' '; cout << '\n';
//						cout << mat(s, j + 1) << '\n';
//						int ss = s ^ 3 << 2 * (j - 1) ^ 1 << 2 * j ^ 1 << 2 * mat(s, j + 1);
//						rep(i, 1, m + 1) cout << bit(ss, i) << ' '; cout << '\n';
//						exit(0); 
//					}
					if(g.count(_s)) chkmx(g[_s], k);
					else g[_s] = k;
				};
				if(l == 0) {
					if(r == 0) {
						insert(s, v);
						insert(s ^ 1 << 2 * (j - 1) ^ 2 << 2 * j, v + a[i][j]);
					}
					else if(r == 1 || r == 2 || r == 3) {
						insert(s, v + a[i][j]);
						insert(s ^ r << 2 * (j - 1) ^ r << 2 * j, v + a[i][j]);
					}
				}
				if(l == 1) {
					if(r == 0) {
						insert(s, v + a[i][j]);
						insert(s ^ 1 << 2 * (j - 1) ^ 1 << 2 * j, v + a[i][j]);
					}
					else if(r == 1) insert(s ^ 1 << 2 * (j - 1) ^ 1 << 2 * j ^ 3 << 2 * mat(s, j + 1), v + a[i][j]);
					else if(r == 2) insert(s ^ 1 << 2 * (j - 1) ^ 2 << 2 * j, v + a[i][j]);
					else if(r == 3) insert(s ^ 1 << 2 * (j - 1) ^ 3 << 2 * j ^ 1 << 2 * mat(s, j), v + a[i][j]);
				}
				if(l == 2) {
					if(r == 0) {
						insert(s, v + a[i][j]);
						insert(s ^ 2 << 2 * (j - 1) ^ 2 << 2 * j, v + a[i][j]);
					}
					else if(r == 1) insert(s ^ 2 << 2 * (j - 1) ^ 1 << 2 * j, v + a[i][j]);
					else if(r == 2) insert(s ^ 2 << 2 * (j - 1) ^ 2 << 2 * j ^ 3 << 2 * mat(s, j), v + a[i][j]);
					else if(r == 3) insert(s ^ 2 << 2 * (j - 1) ^ 3 << 2 * j ^ 2 << 2 * mat(s, j), v + a[i][j]);
				}
				if(l == 3) {
					if(r == 0) {
						insert(s, v + a[i][j]);
						insert(s ^ 3 << 2 * (j - 1) ^ 3 << 2 * j, v + a[i][j]);
					}
					else if(r == 1) insert(s ^ 3 << 2 * (j - 1) ^ 1 << 2 * j ^ 1 << 2 * mat(s, j + 1), v + a[i][j]);
					else if(r == 2) insert(s ^ 3 << 2 * (j - 1) ^ 2 << 2 * j ^ 2 << 2 * mat(s, j + 1), v + a[i][j]);
//					else if(r == 3) {
//						assert(0);
//					}
				}
			}
			swap(f, g);
		}
	}
//	assert(f.count(3 << 2 * m));
	cout << f[3 << 2 * m] << '\n';
	return 0;
}