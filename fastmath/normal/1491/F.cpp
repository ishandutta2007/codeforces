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

vi vec(int l, int r) {
    vi ans;
    for (int i = l; i <= r; ++i)
        ans.app(i);
    return ans;
}

int get(vi l, vi r) {
    cout << "? " << l.size() << ' ' << r.size() << endl;
    cout << l << endl;
    cout << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi ans;
        for (int i = 2; i <= n; ++i) {
            if (get(vec(1, i - 1), vec(i, i))) {
                int l = 1;
                int r = i - 1;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (get(vec(l, m), vec(i, i)))
                        r = m;
                    else
                        l = m + 1;
                }
                for (int j = 1; j < i; ++j) {
                    if (j != l)
                        ans.app(j);
                }
                for (int j = i + 1; j <= n; ++j)
                    if (get(vec(i, i), vec(j, j)) == 0)
                        ans.app(j);
                cout << "! " << ans.size() << ' ' << ans << endl;
                break;
            }
        }
    }
}