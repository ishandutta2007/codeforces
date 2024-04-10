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

const int N = 1e5+7, INF = 314000000;

int m, n;
int out_op[N], rem_op[N];

bool cand_end[N];
bool can_inf[N];

int cost[N];
int from[N];
vi in[N], op[N], to[N];

int mn[N], mx[N];

int dsum[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> m >> n;
    FOR (i, m) {
        cin >> from[i];
        op[from[i]].app(i);
        int k;
        cin >> k;
        rep (k) {
            int x;
            cin >> x;
            if (x == -1) {
                cost[i]++;
            }
            else {
                in[x].app(i);
                to[i].app(x);
            }
        }
        dsum[i] = cost[i];
    }

    FORN (i, n) {
        mn[i] = INF;
        mx[i] = -INF;
    }

{
    set <ii> q;
    FOR (i, m) {
        rem_op[i] = to[i].size();
    }
    FORN (i, n) {
        out_op[i] = op[i].size();
        bool ok = 0;
        each (j, op[i]) {
            if (to[j].empty()) {
                ok = 1;
                ckmin(mn[i], cost[j]);
            }
        }
        if (ok) {
            cand_end[i] = 1;
            q.insert(mp(mn[i], i));
        }
    }
    while (q.size()) {
        int u = q.begin()->y;
        int val = q.begin()->x;
        q.erase(q.begin());
        if (val != mn[u]) {
            continue;
        }
        each (o, in[u]) {
            rem_op[o]--;
            dsum[o] += mn[u];
            if (rem_op[o] == 0) {
                int v = from[o];
                if (!cand_end[v]) {
                    cand_end[v] = 1;
                    ckmin(mn[v], dsum[o]);
                    q.insert(mp(mn[v], v));
                }
                else if (ckmin(mn[v], dsum[o])) {
                    q.insert(mp(mn[v], v));
                }
            }
        }
    }    
}

{
    queue <int> q;
    FOR (i, m) {
        rem_op[i] = to[i].size();
    }
    FORN (i, n) {
        can_inf[i] = 1;
    }
    FORN (i, n) {
        if (cand_end[i]) {
            out_op[i] = 0;
            each (j, op[i]) {

                bool ok = 1;
                each (v, to[j]) {
                    ok &= cand_end[v];
                }

                if (ok && to[j].size()) {
                    out_op[i]++;
                }
            }
            if (out_op[i] == 0) {
                can_inf[i] = 0;
                q.push(i);
            }            
        }
    }
    while (q.size()) {
        int u = q.front(); q.pop();
        each (o, op[u]) {
            {

                bool ok = 1;
                each (v, to[o]) {
                    ok &= cand_end[v];
                }
                if (ok) {
                    int newmx = cost[o];
                    each (v, to[o]) {
                        newmx += mx[v];
                    }
                    ckmax(mx[u], newmx);
                    ckmin(mx[u], INF);                    
                }

            }
        }

        each (o, in[u]) {
            rem_op[o]--;
            if (rem_op[o] == 0) {
                int v = from[o];
                if (cand_end[v]) {
                    
                    out_op[v]--;
                    if (!out_op[v]) {
                        can_inf[v] = 0;
                        q.push(v);
                    }                    
                }
            }
        }
    }    
}

    FORN (i, n) {
        if (!cand_end[i]) {
            cout << -1 << ' ' << -1 << endl;
        }
        else if (can_inf[i]) {
            cout << mn[i] << ' ' << -2 << endl;
        }
        else {
            cout << mn[i] << ' ' << mx[i] << endl;
        }
    }

}