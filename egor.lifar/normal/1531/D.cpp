/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 100228;
const int INF = 1000000000;

int n, q;
string s[MAXN];
set<int> ls;
set<int> rs;



struct node
{
    ll mod = 0;
    ll val = 0;
};



node operator +(const node& a, const node& b) {
    node c;
    c.val = min(a.val, b.val);
    return c;
}


struct rmq
{
    vector<node> d;
    int ss = 1;
    void init(int n) {
        while (ss < n) {
            ss <<= 1;
        }
        d.resize(2 * ss);
    }
    void push(int v) {
        if (d[v].mod != 0) {
            d[v].val += d[v].mod;
            if (v < ss) {
                d[v * 2].mod += d[v].mod;
                d[v * 2 + 1].mod += d[v].mod;
            }
            d[v].mod = 0;
        }
    }
    void add(int v, int vl, int vr, int l, int r, ll x) {
        if (vl > r || vr < l) {
            push(v);
            return;
        }
        if (l <= vl && vr <= r) {
            d[v].mod += x;
            push(v);
            return;
        }
        push(v);
        add(v * 2, vl, (vl + vr) / 2, l, r, x);
        add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
        d[v] = d[v * 2] + d[v * 2 + 1];
    }
    int findlast(int v, int vl, int vr) {
        push(v);
        if (d[v].val > 0) {
            return -1;
        }
        if (vl == vr) {
            return vl - 1;
        }
        int t = findlast(v * 2 + 1, (vl + vr) / 2 + 1, vr);
        if (t != -1) {
            return t;
        }
        return findlast(v * 2, vl, (vl + vr) / 2);
    }
    int findpos() {
        return findlast(1, 1, ss);
    }
} kek;

int findNextL(int pos) {
    auto f = ls.lower_bound(pos);
    if (f == ls.end()) {
        return -1;
    }
    return *f;
}


int findNextR(int pos) {
    auto f = rs.lower_bound(pos);
    if (f == rs.end()) {
        return -1;
    }
    return *f;
}


set<pair<int, int> > cursegs;


void DELSEG(int l, int r) {
    kek.add(1, 1, kek.ss, l + 1, r + 1, -1);
}


void ADDSEG(int l, int r) {
    kek.add(1, 1, kek.ss, l + 1, r + 1, 1);
}


void del(int x) {
    if (s[x] == "lock") {
         kek.add(1, 1, kek.ss, x + 1, x + 1, -INF);
        ls.erase(x);
        auto f = cursegs.lower_bound(mp(x, 0));
        if (f != cursegs.end() && f->first == x) {
            auto d = *f;
            DELSEG(d.first, d.second);
            cursegs.erase(d);
            int k = findNextL(d.first);
            if (k <= d.second && k != -1) {
                ADDSEG(k, d.second);
                cursegs.insert(mp(k, d.second));
            }
        }   
    } else if (s[x] == "unlock") {
         kek.add(1, 1, kek.ss, x + 1, x + 1, -INF);
        rs.erase(x);
        auto f = cursegs.lower_bound(mp(x, 0));
        if (f != cursegs.begin()) {
            f--;
            if (f->second == x) {
                auto d = *f;
                cursegs.erase(d);
                DELSEG(d.first, d.second);
                int t = findNextR(d.first);
                auto k = cursegs.lower_bound(mp(x, 0));
                if (k != cursegs.end() && k->second == t) {
                    auto kk = *k;
                    cursegs.erase(kk);
                    DELSEG(kk.first, kk.second);
                    cursegs.insert(mp(d.first, t));
                    ADDSEG(d.first, t);
                } else {
                    cursegs.insert(mp(d.first, t));
                    ADDSEG(d.first, t);
                }
            }   
        }
    }
}


void add(int x) {
    if (s[x] == "lock") {
         kek.add(1, 1, kek.ss, x + 1, x + 1, INF);
        ls.insert(x);
        auto f = cursegs.lower_bound(mp(x, 0));
        auto f1 = f;
        if (f != cursegs.begin()) {
            f--;
            if (f->first <= x && f->second >= x) {
                return;
            }
        }
        int t = findNextR(x);
        if (t != -1) {
            if (f1 != cursegs.end() && f1->second == t) {
                auto tp = *f1;
                cursegs.erase(tp);
                DELSEG(tp.first, tp.second);
                cursegs.insert(mp(x, tp.second));
                ADDSEG(x, tp.second);
                return;
            }
        }
        if (t != -1) {
            cursegs.insert(mp(x, t));
            ADDSEG(x, t);
        }
    } else if (s[x] == "unlock") {
        kek.add(1, 1, kek.ss, x + 1, x + 1, INF);
        rs.insert(x);
        auto f = cursegs.lower_bound(mp(x, 0));
        auto f1 = f;
        if (f != cursegs.begin()) {
            f--;
            if (f->first <= x && f->second >= x) {
                auto d = *f;
                cursegs.erase(d);
                DELSEG(d.first, d.second);
                int fl = d.second;
                d.second = x;
                cursegs.insert(d);
                ADDSEG(d.first, d.second);
                int keker = findNextL(d.second);
                if (keker <= fl && keker != -1) {
                    ADDSEG(keker, fl);
                    cursegs.insert(mp(keker, fl));
                }
            }
        }
    }
}



void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    s[n] = "unlock";
    n++;
    kek.init(n);
    for (int i = 0; i < kek.ss; i++) {
        kek.add(1, 1, kek.ss, i + 1, i + 1, INF);
    }
    int fk = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == "lock") {
            ls.insert(i);
            if (fk == -1) {
                fk = i;
            }
        } else if (s[i] == "unlock") {
            if (fk != -1) {
                cursegs.insert(mp(fk, i));
                ADDSEG(fk, i);
                fk = -1;
            }
            rs.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != "lock" && s[i] != "unlock") {
            kek.add(1, 1, kek.ss, i + 1, i + 1, -INF);
        }
    }
    int g = kek.findpos();
    if (g == -1) {
        cout << "blue\n";
    } else {
        cout << s[g] << '\n';
    }
    cin >> q;
    // for (auto x: cursegs) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    // cout << endl;
    for (int it = 0; it < q; it++) {
        int id;
        cin >> id;
        id--;
        string pf = s[id];
        string ns;
        cin >> ns;
        del(id);
        // for (auto x: cursegs) {
        //     cout << x.first << ' ' << x.second << '\n';
        // }
        // cout << endl;
        s[id] = ns;
        add(id);
        // for (auto x: cursegs) {
        //     cout << x.first << ' ' << x.second << '\n';
        // }
        // cout << endl;
        // cout << it << ' ' << "change" << ' ' << id << ' ' << pf << ' ' << ns << endl;
        int g = kek.findpos();
        if (g == -1) {
            cout << "blue\n";
        } else {
            // if (s[g] == "orange") {
            //     for (int i = 0; i < n; i++) {
            //         cout << i << ' ' << s[i] << endl;
            //     }
            //     cout << g << '\n';
            //     exit(0);
            // }
            cout << s[g] << '\n';
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}