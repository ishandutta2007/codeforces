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
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (n % k) {
            cout << -1 << endl;
            continue;
        }

        vi cnt(26);
        trav (c, s)
            cnt[c - 'a']++;

        bool ok = 1;
        trav (e, cnt)
            ok &= e%k==0;
        if (ok) {
            cout << s << endl;
            continue;
        }


        auto solve = [&] () {
        vi l = cnt;
        for (int i = n - 1; i >= 0; --i) {
            int cur = s[i] - 'a';
            l[cur]--;   

            int right = n - i - 1;

            for (int c = cur + 1; c < 26; ++c) {
                vi t = l;
                t[c]++;

                int need = 0;
                FOR (j, 26) {
                    if (t[j]%k) {
                        need += k - t[j]%k;
                    }
                }

                if (need <= right) {
                    cout << s.substr(0, i);
                    cout << (char)('a' + c);
                    FOR (j, right - need)
                        cout << 'a';
                    FOR (j, 26) {
                        if (t[j]%k) {
                            FOR (jjj, k - t[j]%k)
                                cout << (char)('a' + j);
                        }
                    }
                    cout << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
        };

        solve();
    }
}