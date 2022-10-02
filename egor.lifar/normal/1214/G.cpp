/*














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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
const string FILENAME = "input";
const int MAXN = 2022;
const unsigned long long kekT = 18446744073709551615ULL;


struct mybitset
{
    vector<unsigned long long> st;
    void init(int n) {
        st.resize(((n + 63) >> 6), 0);
    } 
    void flip(int l, int r) {
        l--, r--;
        for (int i = (l >> 6); i <= (r >> 6); i++) {
            if (i != (l >> 6) && i != (r >> 6)) {
                st[i] ^= kekT;
            } else {
                if (i == (l >> 6) && i == (r >> 6)) { 
                    for (int j = (l & 63); j <= (r & 63); j++) {
                        st[i] ^= (1ULL << j);
                    }
                } else {
                    if (i == (l >> 6)) {
                        for (int j = (l & 63); j < 64; j++) {
                            st[i] ^= (1ULL << j);
                        }
                    } else if (i == (r >> 6)) {
                        for (int j = 0; j <= (r & 63); j++) {
                            st[i] ^= (1ULL << j);
                        }
                    }
                }
            }
        }
    }
    int count() {
        int res = 0;
        for (int i = 0; i < sz(st); i++) {
            res += __builtin_popcountll(st[i]);
        }   
        return res;
    }
};  



mybitset operator ^(const mybitset &a, const mybitset &b) {
    mybitset c;
    c.init(sz(a.st) * 64);
    for (int i = 0; i < sz(a.st); i++) {
        c.st[i] = a.st[i] ^ b.st[i];
    }
    return c;
}


mybitset operator &(const mybitset &a, const mybitset &b) {
    mybitset c;
    c.init(sz(a.st) * 64);
    for (int i = 0; i < sz(a.st); i++) {
        c.st[i] = a.st[i] & b.st[i];
    }
    return c;
}


bool operator ==(const mybitset &a, const mybitset &b) {
    for (int i = 0; i < sz(a.st); i++) {
        if (a.st[i] != b.st[i]) {
            return false;
        }
    }
    return true;
}


int n, m, q;
set<pair<int, int> > st;
mybitset b[MAXN];
int cur[MAXN];
set<pair<int, int> > kek;


void check(int i, int j, int mod) {
    if (!((b[i] & b[j]) == b[i])) {
        if (!((b[i] & b[j]) == b[j])) {
            if (mod == 1) { 
                kek.insert({min(i, j), max(i, j)});
            } else {
                kek.erase({min(i, j), max(i, j)});
            }
        }
    }
}       

void checks(int id, int mod) {
    auto it = st.lower_bound(mp(cur[id], id));
    int frt = -1, ft1 = -1;
    if (it != st.end()) {
        it++;
        if (it != st.end()) {
            frt = it->second;
            check(id, it->second, mod);
        }
        it--;
    }
    if (it != st.begin()) {
        it--;
        ft1 = it->second;
        check(it->second, id, mod);
    }
    if (frt > -1 && ft1 > -1) {
        check(frt, ft1, mod * -1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        b[i].init(m);
        st.insert({0, i});
    }
    for (int it = 0; it < q; it++) {
        int a, l, r;
        cin >> a >> l >> r;
        a--;
        checks(a, -1);
        st.erase({cur[a], a});
        b[a].flip(l, r);
        cur[a] = b[a].count();
        st.insert({cur[a], a});
        checks(a, 1);
        if (kek.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto p = *kek.begin();
        int i = p.first;
        int j = p.second;
        assert(i != j);
        assert(!((b[i] & b[j]) == b[i]));
         assert(!((b[i] & b[j]) == b[j]));
        int pt = -1;
        int pt1 = -1;
        for (int t = 0; t < sz(b[i].st); t++) {
            auto x = b[i].st[t] ^ b[j].st[t];
            if (x & (b[i].st[t])) {
                ull xx = x & (b[i].st[t]);
                if (pt == -1) {
                    for (int k = 0; k < 64; k++) {
                        if (xx & (1ULL << k)) {
                            pt = (t << 6) + k;
                            break; 
                        }
                    }
                }
            }
            if (x & (b[j].st[t])) {
                ull xx = x & (b[j].st[t]);
                if (pt1 == -1) {
                    for (int k = 0; k < 64; k++) {
                        if (xx & (1ULL << k)) {
                            pt1 = (t << 6) + k;
                            break;
                        }
                    }
                }
            }
        }
        if (i > j) {
            swap(i, j);
        }
        if (pt > pt1) {
            swap(pt, pt1);
        }
        cout << i + 1 << ' ' << pt + 1 << ' ' << j + 1 << ' ' << pt1 + 1 << '\n'; 
    }   
    return 0; 
}