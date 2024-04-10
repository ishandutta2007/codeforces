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

const int N = 1e5+7;
int mn[N], mx[N];

string s;
bool check(int n, int &p) {
    if (n == 1) {
        return 1;
    }
 
    int L = n/2;
    int R = (n + 1)/2;
 
    if (!check(L, p)) {
        return 0;
    }
    if (!check(R, p)) {
        return 0;
    }
 
    while (L && R) {
        if (p == s.size()) {
            return 0;
        }
        if (s[p] == '0') {
            L--;
        }
        else {
            R--;
        }
        p++;
    }
 
    return 1;
}

vi restore(int n, int &p) {
    if (n == 1) {
        return {0};
    }

    int L = n/2;
    int R = (n + 1)/2;

    vi l = restore(L, p);
    vi r = restore(R, p);
    trav (e, r) {
        e += L;
    }

    vi ans;
    int pl = 0, pr = 0;
    while (L && R) {
        if (s[p] == '0') {
            ans.app(l[pl]);
            pl++;
            L--;
        }
        else {
            ans.app(r[pr]);
            pr++;
            R--;
        }
        p++;
    }
    while (pl < l.size()) {
        ans.app(l[pl]);
        pl++;
    }
    while (pr < r.size()) {
        ans.app(r[pr]);
        pr++;
    }
    return ans;
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int n = 2; n < N; ++n) {
        mx[n] = mx[(n + 1)/2] + mx[n/2] + n - 1;
        mn[n] = mn[(n + 1)/2] + mn[n/2] + n/2;
    }

    cin >> s;

    int l = 0;
    while (mx[l + 1] < s.size()) {
        l++;
    }

    int r = 100000;
    while (mn[r - 1] > s.size()) {
        r--;
    }

    auto print = [&] (int n) {
        cout << n << endl;
        int p = 0;
        vi ord = restore(n, p);
        vi ans(n);
        FOR (i, n) {
            ans[ord[i]] = i;
        }
        trav (e, ans) {
            cout << e + 1 << ' ';
        }
        cout << endl;
        exit(0);
    };

    while (l < r - 1) {
        int m = (l + r) / 2;

        int p = 0;
        if (!check(m, p)) {
            r = m;
        }
        else if (p < s.size()) {
            l = m;
        }
        else {
            print(m);
        }
    }

    for (int i = max(1, l - 10); ; ++i) {
        int p = 0;
        if (check(i, p) && p == s.size()) {
            print(i);
        }
    }
}