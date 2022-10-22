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

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
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
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

const int N = 1e5+7;
struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    //check r < l!
    return get(r) - get(l - 1);
}   
} f;

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;

    string A = "ANTO";
    auto num = [&] (char c) {
        FOR (i, 4) {
            if (A[i] == c) {
                return i;
            }
        }
        assert(0);
    };  

    auto dist = [&] (string s, string t) {
        int n = s.size();
        V <vi> ps(4), pt(4);
        FOR (i, n) {
            ps[num(s[i])].app(i);
            pt[num(t[i])].app(i);
        }
        vi to(n);
        FOR (c, 4) {
            FOR (i, ps[c].size()) {
                to[ps[c][i]] = pt[c][i];
            }
        }
        reverse(all(to));
        int ans = 0;
        each (x, to) {
            ans += f.get(x);
            f.add(x, 1);
        }

        each (x, to) {
            f.add(x, -1);
        }

        return ans;
    };

    while (t--) {
        string s;
        cin >> s;
        vi cnt(4);
        each (c, s) {
            cnt[num(c)]++;
        }
        vi p(4);
        FOR (i, 4) {
            p[i] = i;
        }
        int ans = -1;
        string best;
        do {
            string t;
            FOR (i, 4) {
                FOR (j, cnt[p[i]]) {
                    t += A[p[i]];
                }
            }
            if (ckmax(ans, dist(s, t))) {
                best = t;
            }
        } while (next_permutation(all(p)));
        //debug(ans);
        //debug(dist(s, "TNNTAOOA"));
        cout << best << endl;
    }
}