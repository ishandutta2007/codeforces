#pragma comment(linker, "/STACK:512000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <ctime>
#include <cassert>
#include <bitset>
#include <cmath>
#include <queue>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef long double ld;

vector<tuple<int, int, int> > q[50000];
int un[50000];

void add(vi &qq, int x, int f, bool &sk) {
    if (x == f && !sk) {
        sk = true;
        return;
    }
    qq.pb(x);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int n;
    scanf("%d", &n);
    forn(i, 4 * n) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b; --c;
        q[a].pb(mt(b, c, i + 1));
    }
    vi ans;
    forn(f, n) {
        while (un[f] < q[f].size()) {
            bool sk = false;
            vi qq;
            qq.pb(f);
            int cur = 0;
            while (cur < qq.size()) {
                int x = qq[cur++];
                if (un[x] == q[x].size()) continue;
                tuple<int, int, int> t = q[x][un[x]++];
                ans.pb(get<2>(t));
                add(qq, get<0>(t), f, sk);
                add(qq, get<1>(t), f, sk);
            }
        }
    }
    cout << "YES\n";
    reverse(all(ans));
    for (int x: ans) cout << x << ' ';
    cout << '\n';

    return 0;
}