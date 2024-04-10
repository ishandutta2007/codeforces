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
#define FORN(i, n) for (int i = 1; i <= n; ++i)
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

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	cin >> a;

    	int sum = 0;
    	trav (e, a) {
    		sum += e;
    	}
    	int mx = (sum-1)/2;

    	M ans = 1;

    	V <vi> pref(n + 1, vi(2));
    	FOR (i, n) {
    		pref[i + 1] = pref[i];
    		pref[i + 1][i & 1] += a[i];
    	}

    	FOR (S, min(n, 2ll)) {
    		if (a[S] <= mx) {
    			int cur = 0;
	    		for (int last = S; last < n; ++last) {
	    			cur += a[last];
	    			if (cur <= mx) {
		    			int l = 0, r = n;
		    			while (l < r - 1) {
		    				int m = (l + r) / 2;
		    				if (last + 2 * m < n && cur + pref[last + 2 * m + 1][last & 1] - pref[last + 1][last & 1] <= mx) {
		    					l = m;
		    				}
		    				else {
		    					r = m;
		    				}
		    			}	
		    			ans += l + 1;    				
	    			}
	    			if (last < n - 1 && cur + a[n - 1] <= mx && last < n - 3) {
		    			int l = 0, r = n;
		    			while (l < r - 1) {
		    				int m = (l + r) / 2;
		    				if (last + 2 * m < n - 3 && cur + pref[last + 2 * m + 1][last & 1] - pref[last + 1][last & 1] + a[n - 1] <= mx) {
		    					l = m;
		    				}
		    				else {
		    					r = m;
		    				}
		    			}	
		    			ans += l + 1; 	    				
	    			}
	    		}    			
    		}
    	}

    	int suf = 0;
    	for (int i = n - 1; i >= 2; --i) {
    		suf += a[i];
    		if (suf <= mx) {
    			ans += 1;
    		}
    	}

    	cout << ans << endl;
    }
}