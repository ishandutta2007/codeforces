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

    int n, m;
    cin >> n >> m;

    V <vi> a(n, vi (m));
    FOR (i, n)
        re(a[i]);

    auto check = [&] (vi cand) {
        FOR (i, n) {
            int sh = 0;
            FOR (j, m) {
                sh += cand[j] != a[i][j];
            }
            if (sh > 2)
                return;
        }
        cout << "Yes" << endl;
        cout << cand << endl;
        exit(0);
    };

    auto gg = [&] () {
        cout << "No" << endl;
        exit(0);
    };

    auto solve = [&] (V <vi> a, int P) {
        V <vi> dif(n);
        for (int i = 1; i < n; ++i) {
            FOR (j, m) {
                if (a[i][j] != a[0][j]) {
                    dif[i].app(j);
                }
            }
            if (dif[i].size() > 4) {
                return;
            }
        }

        check(a[0]);

        FOR (p, m) {
            vi c(n, 2);
            for (int i = 1; i < n; ++i) {
                trav (e, dif[i]) {
                    if (e != P && e != p && a[0][e] != a[i][e]) {
                        c[i]--;
                    }
                }
            }
            FOR (i, n) {
                if (c[i] == 0) {
                    vi ans = a[0];
                    ans[p] = a[i][p];
                    ans[P] = a[i][P];
                    check(ans);
                    break;
                }
                if (c[i] == 1) {
                    //p
                    auto c1 = c;
                    FOR (i1, n) {
                        if (a[i1][p] != a[i][p])
                            c1[i1]--;
                    }
                    FOR (i1, n) {
                        if (c1[i1] == 0) {
                            auto ans = a[0];
                            ans[p] = a[i][p];
                            ans[P] = a[i1][P];
                            check(ans);
                            break;
                        }
                    }
                    auto ans = a[0];
                    ans[p] = a[i][p];
                    ans[P] = 1;
                    check(ans);

                    //P
                    c1 = c;
                    FOR (i1, n) {
                        if (a[i1][P] != a[i][P])
                            c1[i1]--;
                    }
                    FOR (i1, n) {
                        if (c1[i1] == 0) {
                            auto ans = a[0];
                            ans[P] = a[i][P];
                            ans[p] = a[i1][p];
                            check(ans);
                            break;
                        }
                    }
                    ans = a[0];
                    ans[P] = a[i][P];
                    ans[p] = 1;
                    check(ans);

                    break;
                }
            }
        }
    };
    check(a[0]);
    for (int i = 1; i < n; ++i) {
        FOR (j, m) {
            if (a[i][j] != a[0][j]) {
                solve(a, j);
                swap(a[i], a[0]);
                solve(a, j);
                cout << "No" << endl;
                exit(0);
            }
        }
    }
}