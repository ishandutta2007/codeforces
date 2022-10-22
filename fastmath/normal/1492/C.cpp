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

vi pos[26];

signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vi pref(n + 1), suf(n + 1);

    FOR (i, n)
        pos[s[i] - 'a'].app(i);

    int cur = 0;
    FOR (i, n) {
        if (cur < m && s[i] == t[cur])
            cur++;
        pref[i + 1] = cur;
    }

    string rt = t;
    reverse(all(rt));

    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (cur < m && s[i] == rt[cur])
            cur++;
        suf[i] = cur;
    }

    int ans = 0;
    FOR (i, m - 1) {
        int a = t[i] - 'a', b = t[i + 1] - 'a';

        int L = -1, R = -1;

        {
        int l = -1, r = pos[a].size();
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            int p = pos[a][mid];
            if (pref[p] >= i)
                r = mid;
            else
                l = mid;
        }
        L = pos[a][r];
        }

        {
        int l = -1, r = pos[b].size();
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            int p = pos[b][mid];
            if (suf[p + 1] >= m - i - 2)
                l = mid;
            else
                r = mid;
        }
        R = pos[b][l];
        }

        ckmax(ans, R - L);
    }
    cout << ans << endl;
}