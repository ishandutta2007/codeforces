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
#include <stack>
#include <memory>
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

#ifdef LOCAL
mt19937 rnd(2007);
#else
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif

signed main() {
    /*
    mt19937 rnd(2007);
    int n = 20, w = 13;
    rep (100000) {
        V <string> a;

        a.app("");
        rep (n) a.back() += '0';

        rep (w) {
            a.app("");
            rep (n) {
                a.back() += (char)('0' + (rnd()&1));
            }
        }
        set <vi> ha;
        FOR (mask, 1 << n) {
            vi h;
            each (s, a) {
                int sov = 0;
                FOR (i, n) {
                    sov += Bit(mask, i) == (s[i] - '0');
                }
                h.app(sov);
            }

            int f = h[0];
            each (e, h) e -= f;

            if (ha.find(h) != ha.end()) break;
            ha.insert(h);
        }
        debug(ha.size());
        if (ha.size() == (1 << n)) {
            for (int i = 1; i <= w; ++i) {
                cout << "a[" << i - 1 << "]=" << a[i] << endl;
            }
            //debug(a);
            exit(0);
        }
        else if (_%1000 == 0) {
            debug(_);
        }   
    }  
    */

    V <vi> h(1 << 20);

    V <string> a(13);
a[0]="10111100101010010111";
a[1]="00011011110110010110";
a[2]="01100011001110001100";
a[3]="01110001101011010001";
a[4]="10100001110110111000";
a[5]="11001011001111011100";
a[6]="01011100010100001001";
a[7]="11110011111011110010";
a[8]="10011101010101111101";
a[9]="11101110001000111111";
a[10]="11101101100010010101";
a[11]="10101101100011000000";
a[12]="01100100001011011111";

    //int our = (1 << 20) - 1 - 4;

    int b = 20;
    FOR (mask, 1 << b) {

        int c0 = 0;
        FOR (i, b) {
            c0 += Bit(mask, i) == 0;
        }

        each (s, a) {
            int sov = 0;
            FOR (i, b) {
                sov += Bit(mask, i) == (s[i] - '0');
            }
            h[mask].app(sov - c0);
        }

        /*
        string who;
        FOR (i, b) {
            who += (char)(Bit(mask, i) + '0');
        }
        */

        /*
        if (mask == our) {
            debug(h);
        }
        */

        //d[h] = who;
    }

    int n;
    cin >> n;

    #ifdef LOCAL
    string ANS;
    cin >> ANS;
    #endif  

    auto ask = [&] (string s) {
        while (s.size() > n) s.pop_back();
        FOR (i, n) {
            if (s[i] == '0') {
                s[i] = 'T';
            }
            else {
                s[i] = 'F';
            }
        }
        cout << s << endl;

        int ans;
        #ifdef LOCAL
        ans = 0;
        FOR (i, n) {
            ans += s[i] == ANS[i];
        }
        if (ans == n) {
            exit(0);
        }
        return ans;
        #endif

        cin >> ans;
        if (ans == n) {
            exit(0);
        }
        return ans;
    };

    string s0;
    FOR (i, n) s0 += '0';
    int t0 = ask(s0);

    auto Delta = [&] (int l, string sub) {
        auto s = s0;
        for (int i = l; i < n && i < l + b; ++i) {
            s[i] = sub[i - l];
        }
        int ans = ask(s);
        for (int i = l; i < l + b; ++i) {
            if (i >= n) {
                ans += sub[i - l] == '1';
            }
        }
        return ans - t0;
    };

    string ans;
    for (int l = 0; l < n; l += b) {
        vi hw;
        each (e, a) {
            hw.app(Delta(l, e));
        }

        FOR (mask, 1 << b) {
            if (h[mask] == hw) {
                FOR (i, b) {
                    if (Bit(mask, i)) {
                        ans += '1';
                    }
                    else {
                        ans += '0';
                    }
                }
                break;
            }
        }
    }
    ask(ans);
}