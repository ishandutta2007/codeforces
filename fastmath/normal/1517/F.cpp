#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}

//need define int long long
namespace Stuff {
const int MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }
};
struct M {
ll x;
M (int x_) { x = Stuff::mod(x_); }   
M () { x = 0; }
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= Stuff::MOD)
        ans -= Stuff::MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += Stuff::MOD;
    return M(ans);            
}   
M operator * (M y) { return M(x * y.x % Stuff::MOD); }   
M operator / (M y) { return M(x * Stuff::fp(y.x, Stuff::MOD - 2) % Stuff::MOD); }   
M operator + (int y) { return (*this) + M(y); }
M operator - (int y) { return (*this) - M(y); }   
M operator * (int y) { return (*this) * M(y); }   
M operator / (int y) { return (*this) / M(y); }   
M operator ^ (int p) { return M(Stuff::fp(x, p)); }   
void operator += (M y) { *this = *this + y; }   
void operator -= (M y) { *this = *this - y; }   
void operator *= (M y) { *this = *this * y; }
void operator /= (M y) { *this = *this / y; }   
void operator += (int y) { *this = *this + y; }   
void operator -= (int y) { *this = *this - y; }   
void operator *= (int y) { *this = *this * y; }
void operator /= (int y) { *this = *this / y; }   
void operator ^= (int p) { *this = *this ^ p; }
bool operator == (M y) { return x == y.x; }
};  
std::ostream& operator << (std::ostream& o, const M& a)
{
    cout << a.x;
    return o;
}

const int N = 307;
int n;
vi g[N];
M down[N][N], up[N][N];
M p[N];
vi tree[N];
void calc(int u, int p) {
	trav (v, g[u]) {
		if (v != p) {
			tree[u].app(v);	
			calc(v, u);
		}
	}
}

M cdown_[N][2][N], cup_[N][2][N];
void dfs(int u, int D) {
	auto cdown = cdown_[u];
	auto cup = cup_[u];

	FOR (i, 2) {
		FOR (j, N) {
			cdown[i][j] = cup[i][j] = 0;
		}
	}

	cdown[0][0] = M(1)/2;
	cup[0][D] = M(1)/2;
	trav (v, tree[u]) {
		dfs(v, D);
		FOR (i, N) {
			cdown[1][i] = cup[1][i] = 0;
		}
		FOR (i, N) {
			if (cdown[0][i].x) {
				FOR (j, N) {
					cdown[1][max(i, j + 1)] += cdown[0][i] * down[v][j];
					if (j >= i + 1) {
						cup[1][j - 1] += cdown[0][i] * up[v][j];
					}			
					else {
						cdown[1][i] += cdown[0][i] * up[v][j];
					}
				}				
			}
			if (cup[0][i].x) {
				FOR (j, N) {
					if (i >= j + 1) {
						cup[1][i] += cup[0][i] * down[v][j];
					}	
					else {
						cdown[1][j + 1] += cup[0][i] * down[v][j];
					}
					cup[1][max(i, j - 1)] += cup[0][i] * up[v][j];
				}				
			}
		}
		FOR (i, N) {
			cdown[0][i] = cdown[1][i];
			cup[0][i] = cup[1][i];
		}
	}

	FOR (i, N) {
		down[u][i] = cdown[0][i];
		up[u][i] = cup[0][i];
	}
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    FOR (i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }

    calc(1, 1);
    for (int i = 0; i <= n; ++i) {
    	dfs(1, i);
    	for (int j = 0; j < N; ++j) {
    		p[i] += up[1][j];
    	}
    }
    M ans = M(n-1) / (M(2) ^ n);
    for (int i = 0; i < n; ++i) {
    	ans += (p[i + 1] - p[i]) * i;
    }
    cout << ans << endl;
}