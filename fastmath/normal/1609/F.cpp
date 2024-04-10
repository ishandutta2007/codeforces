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
#include <array>
#include <functional>
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

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif

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
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
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

const int B = 60, N = 1e6+7;

ll a[N];
signed pref[N][B];
int l[N], r[N], s[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    FOR (i, n) {
        cin >> a[i];
    }

    FOR (i, n) {
        l[i] = -1;
        r[i] = n;
    }

    {
    int sz = 0;
    FOR (i, n) {
        while (sz && mp(a[s[sz - 1]], s[sz - 1]) < mp(a[i], i)) {
            sz--;
        }
        if (sz) l[i] = s[sz - 1];
        s[sz++] = i;
    }        
    }

    {
    int sz = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (sz && mp(a[s[sz - 1]], s[sz - 1]) < mp(a[i], i)) {
            sz--;
        }
        if (sz) r[i] = s[sz - 1];
        s[sz++] = i;      
    }
    }

    ll ans = 0;

    {
    int sz = 0;

    auto get_pref_2 = [&] (int i, int want) {
        int l = -1, r = sz;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (s[m] <= i) {
                l = m;
            }
            else {
                r = m;
            }
        }

        int ans = pref[l + 1][want];

        int link = -1;
        if (l != -1) link = s[l];

        int gap = i - link;

        if (bp(a[s[r]]) == want) {
            ans += gap;
        }
        return ans;
    };  

    auto get2 = [&] (int l, int r, int want) {
        return get_pref_2(r, want) - get_pref_2(l, want);
    };

    FOR (i, n) {
        while (sz && mp(a[s[sz - 1]], s[sz - 1]) > mp(a[i], i)) {
            sz--;
        }

        int dist = i + 1;
        if (sz) dist = i - s[sz - 1];

        s[sz++] = i;

        FOR (bit, B) {
            pref[sz][bit] = pref[sz-1][bit];
        }
        pref[sz][bp(a[i])] += dist;

        if (!(i - l[i] < r[i] - i)) {
            debug(i);

            int mn = i;
            for (int j = i; j < r[i]; ++j) {
                if (mp(a[j], j) < mp(a[mn], mn)) mn = j;

                int first_smaller = -1;
                {
                int bpl = -1, bpr = sz;
                while (bpl < bpr - 1) {
                    int m = (bpl + bpr) / 2;
                    if (mp(a[s[m]], s[m]) < mp(a[mn], mn)) {
                        bpl = m;
                    }
                    else {
                        bpr = m;
                    }
                }
                first_smaller = bpl;
                }

                int we_are_min_until = -1;
                if (first_smaller != -1) {
                    we_are_min_until = s[first_smaller];    
                }
                if (bp(a[mn]) == bp(a[i])) {
                    ans += i - max(we_are_min_until, l[i]);
                }
                if (we_are_min_until > l[i]) {
                    ans += get2(l[i], we_are_min_until, bp(a[i]));
                }
            }

            debug(ans);
        }

    }        
    }

    debug("tak");

    {
    int sz = 0;
    auto get_pref_1 = [&] (int i, int want) {
        int l = -1, r = sz;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (s[m] >= i) {
                l = m;
            }
            else {
                r = m;
            }
        }

        int ans = pref[l + 1][want];

        int link = n;
        if (l != -1) link = s[l];

        int gap = link - i;

        if (bp(a[s[r]]) == want) {
            ans += gap;
        }
        return ans;
    };  

    auto get1 = [&] (int l, int r, int want) {
        debug(s);
        debug(mp(l, r));
        debug(get_pref_1(l, want));
        debug(get_pref_1(r, want));
        return get_pref_1(l, want) - get_pref_1(r, want);
    };

    for (int i = n - 1; i >= 0; --i) {
        while (sz && mp(a[s[sz - 1]], s[sz - 1]) > mp(a[i], i)) {
            sz--;
        }

        int dist = n - i;
        if (sz) dist = s[sz - 1] - i;

        s[sz++] = i;

        FOR (bit, B) {
            pref[sz][bit] = pref[sz-1][bit];
        }
        pref[sz][bp(a[i])] += dist;

        debug(i);

        int pos = -1;
        {
        int bpl = -1, bpr = sz;
        while (bpl < bpr - 1) {
            int m = (bpl + bpr) / 2;
            if (s[m] >= r[i]) {
                bpl = m;
            }
            else {
                bpr = m;
            }
        }
        pos = bpl;
        }

        debug(pos);

        if (i - l[i] < r[i] - i) {
            int mn = i;
            for (int j = i; j > l[i]; --j) {
                if (mp(a[j], j) < mp(a[mn], mn)) mn = j;

                int first_smaller = -1;
                {
                int bpl = -1, bpr = sz;
                while (bpl < bpr - 1) {
                    int m = (bpl + bpr) / 2;
                    if (mp(a[s[m]], s[m]) < mp(a[mn], mn)) {
                        bpl = m;
                    }
                    else {
                        bpr = m;
                    }
                }
                first_smaller = bpl;
                }

                int we_are_min_until = n;
                if (first_smaller != -1) {
                    we_are_min_until = s[first_smaller];    
                }
                if (bp(a[mn]) == bp(a[i])) {
                    ans += min(we_are_min_until, r[i]) - i;
                }

                if (we_are_min_until < r[i]) {
                    ans += get1(we_are_min_until, r[i], bp(a[i]));
                }

                debug(j);
                debug(we_are_min_until);
                debug(ans);
                debug(mn);
            }
        }

        debug(ans);
        cout << endl << endl << endl;
    } 
    }

    cout << ans << endl;
}