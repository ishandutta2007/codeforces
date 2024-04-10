#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    while (cin >> s) {
//        cerr << s << '\n';
        vvi seq;
        vi q[2][2];
        forn(j, 2) forn(k, 2) q[j][k].clear();
        seq.clear();
        forn(i, s.size()) {
            char c = s[i];
            int x = c == 'R', y = !x;
            int s;
            if (!q[x][y].empty()) s = x;
            else if (!q[y][y].empty()) s = y;
            else {
                q[x][y].pb(seq.size());
                seq.pb(vi());
                s = x;
            }
            int z = q[s][y].back();
            seq[z].pb(i + 1);
            q[s][y].pop_back();
            q[s][x].pb(z);
        }
        assert(!q[0][0].empty() || !q[1][1].empty() || q[0][1].empty() || q[1][0].empty());
        cout << seq.size() - 1 << '\n';
        int x = 0, y = 1;
        if (q[0][0].size() < q[1][1].size()) swap(x, y);
        if (q[x][x].empty() && q[x][y].empty()) swap(x, y);
        while (!q[x][y].empty()) {
            int z = q[x][y].back();
            q[x][y].pop_back();
            for (int t: seq[z]) cout << t << ' ';
        }
        while (!q[y][y].empty()) {
            int z = q[x][x].back();
            q[x][x].pop_back();
            for (int t: seq[z]) cout << t << ' ';

            while (!q[y][x].empty()) {
                int z = q[y][x].back();
                q[y][x].pop_back();
                for (int t: seq[z]) cout << t << ' ';
            }

            z = q[y][y].back();
            q[y][y].pop_back();
            for (int t: seq[z]) cout << t << ' ';
        }
        if (!q[x][x].empty()) {
            int z = q[x][x].back();
            q[x][x].pop_back();
            for (int t: seq[z]) cout << t << ' ';
            assert(q[x][x].empty());
            swap(x, y);
        }
        while (!q[x][y].empty()) {
            int z = q[x][y].back();
            q[x][y].pop_back();
            for (int t: seq[z]) cout << t << ' ';
        }
        cout << '\n';
        forn(j, 2) forn(k, 2) assert(q[j][k].empty());
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}