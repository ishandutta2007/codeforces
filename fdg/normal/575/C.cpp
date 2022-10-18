#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O500")
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
typedef unsigned long long ull;
typedef complex < double > cd;
typedef long double ld;
typedef long long ll;
 
template < class T > void read(T &x) { char c, mi = 0; while(c = getchar(), c <= 32); if(c == '-') mi = 1, x = 0; else if(c < 48 || c > 57) return void(x = c); else x = c - 48; while(c = getchar(), c > 32) x = 10 * x + c - 48; if(mi == 1) x = -x; }
template < class T > void read(T &x, T &y) { read(x); read(y); }
template < class T > void read(T &x, T &y, T &z) { read(x, y); read(z); }
template < class T > void reada(T *a, int n) { for(int i = 0; i < n; ++i) read(a[i]); }
template < class T > void write(T x) { static char s[20]; char pt = 0, mi = (x < 0); if(mi == 1) x = -x; while(!pt || x > 0) { s[++pt] = (char)(x % 10 + '0'); x /= 10; } if(mi == 1) putchar('-'); while(pt > 0) putchar(s[pt--]); }
template < class T > void write(T x, T y) { write(x); putchar(' '); write(y); }
template < class T > void write(T x, T y, T z) { write(x, y); putchar(' '); write(z); }
template < class T > void writeln(T x) { write(x); puts(""); }
template < class T > void writea(T *a, int n) { for(int i = 0; i < n; ++i) { write(a[i]); putchar(i + 1 == n ? '\n' : ' '); } }
template < class T > T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template < class T > T lcm(T a, T b) { return a / gcd(a, b) * b; }
template < class T > T qpom(T a, T b, int mod = 1000000007) { T r = 1; while(b > 0) { if(b & 1) r = r * a % mod; a = a * a % mod; b /= 2; } return r; }
template < class T > T qpow(T a, T b) { T r = 1; while(b > 0) { if(b & 1) r *= a; a *= a; b /= 2; } return r; }
template < class T > T imin(T a, T b) { return a < b ? a : b; }
template < class T > T imax(T a, T b) { return a > b ? a : b; }
template < class T > inline void rmin(T &a, const T &b) { if(a > b) a = b; }
template < class T > inline void rmax(T &a, const T &b) { if(a < b) a = b; }
template < class T > T sqr(const T &a) { return a * a; }
 
#define debug(x) cout << #x << "=" << x
#define debuge(x, c) cout << #x << "=" << x << (c)
#define debugn(x) cout << #x << "=" << x << "\n"
#ifndef DEBUG
#define eprintf(...) fprintf(stderr, "%s -> ", string(to_string((long long)__LINE__)).c_str()), fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
 
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
 
#define inf 1000000007
#define nmax 2000010
#define mmax 30010
#define eps 1e-9

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
#define PI 2 * acos(0)
#define ms(a,x) memset(a, x, sizeof(a))

#define maxn 22


struct Hungary {
    int nx, ny, cost[maxn][maxn], fx[maxn], fy[maxn], maty[maxn], which[maxn], dist[maxn], maxmat;
    bool used[maxn], sw;

    void init(int _nx, int _ny) {
        sw = 0; if (_nx > _ny) { swap(_nx, _ny); sw = 1; } // Because nx <= ny
        nx = _nx; ny = _ny; ms(fx, 0); ms(fy, 0); ms(maty, 0);
        For(i, 0, nx) For(j, 0, ny) cost[i][j] = inf;
    }

    void add(int x, int y, int c) { if (sw) swap(x, y); cost[x][y] = c; }

    int mincost() {
        For(x, 1, nx) {
            int y0 = 0; maty[0] = x;
            For(y, 0, ny) { dist[y] = inf + 1; used[y] = false; }

            do {
                used[y0] = true;
                int x0 = maty[y0], delta = inf + 1, y1;

                For(y, 1, ny) if (!used[y]) {
                    int curdist = cost[x0][y] - fx[x0] - fy[y];
                    if (curdist < dist[y]) {
                        dist[y] = curdist;
                        which[y] = y0;
                    }
                    if (dist[y] < delta) {
                        delta = dist[y];
                        y1 = y;
                    }
                }

                For(y, 0, ny) if (used[y]) {
                    fx[maty[y]] += delta;
                    fy[y] -= delta;
                } else dist[y] -= delta;

                y0 = y1;
            } while (maty[y0] != 0);

            do {
                int y1 = which[y0];
                maty[y0] = maty[y1];
                y0 = y1;
            } while (y0);
        }

        int ret = 0; maxmat = 0;
        For(y, 1, ny) {
            int x = maty[y];
            if (cost[x][y] < inf) { ret += cost[x][y]; ++maxmat; }
        }
        return ret;
    }
} hungary;

int A[22][22], a[22][22], b[22][22], n;
clock_t start = clock();

int solve(int mask) {
	for(int i = 0; i < n; ++i) {
		if(mask & (1 << i)) {
			for(int j = 1; j <= n; ++j) {
				A[i + 1][j] = -a[i + 1][j];
			}
		} else {
			for(int j = 1; j <= n; ++j) {
				A[i + 1][j] = -b[i + 1][j];
			}
		}
	}
	hungary.init(n, n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			hungary.add(i, j, A[i][j]);
		}
	}
	return -hungary.mincost();
}

int main() {
//	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
//	freopen("invers.in", "r", stdin); freopen("invers.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> b[i][j];
		}
	}
	int ans = 0;
	vector < int > perm;
	for(int mask = 0; mask < 1 << n; ++mask) {
		int bits = 0;
		for(int i = 0; i < n; ++i) {
			if(mask & (1 << i)) {
				bits += 1;
			}
		}
		if(bits != n / 2) {
			continue;
		}
		perm.push_back(mask);
	}
	random_shuffle(perm.begin(), perm.end());
	for(int i = 0; i < (int)perm.size(); ++i) {
		ans = max(ans, solve(perm[i]));
		if(i % 50 == 0 && clock() - start >= 1.75 * CLOCKS_PER_SEC) {
			printf("%d\n", ans);
			exit(0);
		}
	}
	cout << ans << '\n';
	getchar(); getchar();
	return 0;
}