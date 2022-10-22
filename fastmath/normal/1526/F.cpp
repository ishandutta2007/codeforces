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

mt19937 rnd(3017568);
int get(int l, int r) {
    return rnd() % (r - l + 1) + l;
}

signed main() {

    auto solve = [&] () {
        int n;
        #ifdef LOCAL
        
        
        n = get(5, 30);
        vi p(n + 1);
        FORN (i, n) {
            p[i] = i;
        }
        shuffle(p.begin() + 1, p.begin() + n + 1, rnd);
        if (p[2] < p[1]) {
            swap(p[1], p[2]);
        }
        
        /*
        cin >> n;
        vi p(n + 1);
        FORN (i, n) {
            cin >> p[i];
        }
        */

        //debug(p);

        #else
        cin >> n;
        #endif

        int Q = 0;

        auto get = [&] (int a, int b, int c) {
            Q++;

            assert(Q < 2 * n + 30);
            assert(1 <= a && a <= n);
            assert(1 <= b && b <= n);
            assert(1 <= c && c <= n);
            assert(a != b && b != c && a != c);

            #ifdef LOCAL
            vi v = {abs(p[a] - p[b]), abs(p[a] - p[c]), abs(p[b] - p[c])};
            sort(all(v));
            int res = v[1];
            return res;
            #else
            cout << "? " << a << ' ' << b << ' ' << c << endl;
            int ans; cin >> ans; return ans;
            #endif
        };  

        vi with(n + 1);
        int mn = n + 1, cnt = 0;
        set <int> ms;
        for (int i = 3; i <= n; ++i) {
            with[i] = get(1, 2, i);
            ms.insert(with[i]);
            if (with[i] < mn) {
                mn = with[i];
                cnt = 1;
            }
            else if (mn == with[i]) {
                cnt++;
            }
        }

        vi from_L(n + 1);
        if (mn == 1 && (cnt == 2 || ms.size() == n - 2)) {
            vi d1, d2;
            for (int i = 3; i <= n; ++i) {
                if (with[i] == 1) {
                    d1.app(i);
                }
                if (with[i] == 2) {
                    d2.app(i);
                }
            }

            int prv = -1, pp = -1, nxt = -1, nn = -1;

            each (a, d1) {
                each (b, d2) {
                    if (get(a, b, 1) == 1) {
                        prv = a;
                        pp = b;
                    }
                    if (get(a, b, 2) == 1) {
                        nxt = a;
                        nn = b;
                    }
                }
            }

            //debug(prv); debug(nxt);

            from_L[2] = 1;
            if (prv != -1) {
                for (int i = 3; i <= n; ++i) {
                    if (i == prv) {
                        from_L[i] = -1;
                        continue;
                    }
                    if (i == nxt) {
                        from_L[i] = 2;
                        continue;
                    }
                    int x = get(1, prv, i);
                    if (x < with[i]) {
                        from_L[i] = -with[i];
                    }
                    else {
                        from_L[i] = with[i] + 1;
                    }
                }
            }
            else if (nxt != -1) {
                for (int i = 3; i <= n; ++i) {
                    if (i == prv) {
                        from_L[i] = -1;
                        continue;
                    }
                    if (i == nxt) {
                        from_L[i] = 2;
                        continue;
                    }
                    int x = get(2, nxt, i);
                    if (x < with[i]) {
                        from_L[i] = with[i] + 1;
                    }
                    else {
                        from_L[i] = -with[i];
                    }
                }
            }
            else {
                assert(0);
            }
        }
        else {
            int d = mn * 2;
            assert(cnt == 1 || cnt == 2);
            if (cnt == 2) {
                d--;
            }

            from_L[2] = d;

            vi who, in, out_b, out_f;
            for (int i = 3; i <= n; ++i) {
                if (with[i] < d) {
                    in.app(i);
                    if (with[i] == mn) {
                        who.app(i);
                    }
                }
                else if (with[i] == d) {
                    out_b.app(i);
                }
                else {
                    out_f.app(i);
                }
            }

            //debug(n);
            //debug(Q);

            int nxt = -1;

            //debug(in); debug(who);

            //need to find nxt!

            vi X(n + 1);
            int maxx = 0;
            each (i, in) {
                if (i == who[0]) {
                    continue;
                }
                if (who.size() > 1 && i == who[1]) {
                    continue;
                }
                X[i] = get(1, who[0], i);
                ckmax(maxx, X[i]);    
            }
            each (i, in) {
                if (i == who[0]) {
                    continue;
                }
                if (who.size() > 1 && i == who[1]) {
                    continue;
                }
                if (X[i] < maxx) {
                    from_L[i] = d - with[i];
                }
                else {
                    from_L[i] = with[i];
                }       
                //debug(i);
                //assert(from_L[i] == p[i] - p[1]);
                if (from_L[i] == 1) {
                    nxt = i;
                }           
            }

            if (in.size() == 1) {
                nxt = in[0];
                from_L[nxt] = 1;
            }

            if (who.size() == 1) {
                from_L[who[0]] = mn;
            }

            if (nxt == -1) {
                assert(d == 3);
                each (i, out_b) {
                    each (e, who) {
                        if (get(1, e, i) == 1) {
                            nxt = e;
                            break;
                        }
                        if (get(2, e, i) == 1) {
                            nxt = who[0] ^ who[1] ^ e;
                            break;
                        }
                    }
                }
                assert(nxt != -1);   
                from_L[nxt] = 1;
                from_L[nxt ^ who[0] ^ who[1]] = 2;
            }

            //debug(nxt);

            if (who.size() == 2 && from_L[who[0]] == 0) {
                //debug("tak"); debug(who);
                if (get(1, nxt, who[0]) == d/2) {
                    swap(who[0], who[1]);
                }
                from_L[who[0]] = mn - 1;
                from_L[who[1]] = mn;
            }

            int prv = -1;
            each (e, in) {
                if (from_L[e] == d - 1) {
                    prv = e;
                }
            }
            assert(prv != -1);

            each (i, out_b) {
                int x = get(1, nxt, i);
                if (x == d) {
                    if (get(2, prv, i) == 1) {
                        from_L[i] = d + 1;
                    }
                    else {
                        from_L[i] = -d;
                    }
                }
                else if (x < d) {
                    from_L[i] = -x;
                }
                else if (x > d) {
                    from_L[i] = x + 1;
                }
            }
            each (i, out_f) {
                int x = get(1, nxt, i);
                if (x == with[i]) {
                    from_L[i] = -with[i];
                }
                else {
                    from_L[i] = with[i] + d;
                }
            }
        }

        int LV = 1;
        FORN (i, n) {
            if (from_L[i] < 0) {
                LV++;
            }
        }

        vi ans(n + 1);
        FORN (i, n) {
            ans[i] = LV + from_L[i];
        }

        #ifndef LOCAL
        cout << "! ";
        FORN (i, n) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        int kek; cin >> kek;
        #endif

        #ifdef LOCAL
        assert(ans == p);
        #endif
    };

    #ifdef LOCAL
    FOR (test, 1000 * 1000 * 1000) {
        solve();
        debug(test);
    }
    #else
    int t;
    cin >> t;
    while (t--) {
        solve();    
    }
    #endif
}