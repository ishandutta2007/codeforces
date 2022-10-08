#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 300 * 1000;
const int mdl = 998244353;

int mindiv[maxn];
int invints[maxn];
vector <pair <int, pair <int, int> > > vertex[maxn];
bool used[maxn];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long long pwr(long long a, long long b) {
    if (b == 0) {
        return 1ll;
    }
    if (b % 2 == 1) {
        return pwr(a, b - 1) * a % mdl;
    } else {
        long long d = pwr(a, b / 2);
        return d * d % mdl;
    }
}

long long getinv(long long x) {
    return pwr(x, mdl - 2);
}

void precalc() {
    for (int i = 1; i < maxn; i++) {
        mindiv[i] = i;
    }
    for (int i = 2; i < maxn; i++) {
        if (mindiv[i] == i) {
            for (int j = 2; i * j < maxn; j++) {
                mindiv[i * j] = min(mindiv[i * j], i);
            }
        }
    }

    for (int i = 1; i < maxn; i++) {
        invints[i] = getinv(i);
    }
}

void process(int x, int sgn, unordered_map <int, int>& curdeg, unordered_map <int, int>& mindeg) {
    int lst = -1;
    while (x > 1) {
        lst = mindiv[x];
        curdeg[lst] += sgn;
        x /= mindiv[x];

        mindeg[lst] = min(mindeg[lst], curdeg[lst]);
    }
}

long long dfs(int v, long long cur, unordered_map <int, int>& curdeg, unordered_map <int, int>& mindeg) {
//    cerr << v << ' ' << cur << endl;
    long long sum = cur;
    used[v] = true;

    for (auto e : vertex[v]) {
//        cerr << e.fs << ' ' << e.sc.fs << ' ' << e.sc.sc << endl;
        if (!used[e.fs]) {
            long long ncur = (((cur * e.sc.fs) % mdl) * invints[e.sc.sc]) % mdl;

            process(e.sc.fs, 1, curdeg, mindeg);
            process(e.sc.sc, -1, curdeg, mindeg);
            sum += dfs(e.fs, ncur, curdeg, mindeg);
            sum %= mdl;
            process(e.sc.sc, 1, curdeg, mindeg);
            process(e.sc.fs, -1, curdeg, mindeg);
        }
    }

    return sum;
}

int main() {
    precalc();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
//        cerr << n << endl;
        for (int i = 0; i < n; i++) {
            vertex[i].clear();
            used[i] = false;
        }

        unordered_map <int, int> curdeg, mindeg;

        for (int i = 0; i < n - 1; i++) {
            int u, v, x, y;
            cin >> u >> v >> y >> x;
//            cerr << u << ' ' << v << ' ' << y << ' ' << x << endl;

            u--, v--;
            vertex[u].pb(mp(v, mp(x, y)));
            vertex[v].pb(mp(u, mp(y, x)));
        }

        long long ans = dfs(0, 1ll, curdeg, mindeg);
        for (auto& e : mindeg) {
            for (int i = 0; i < -e.sc; i++) {
                ans = (ans * e.fs) % mdl;
            }
        }

        cout << ans << endl;
    }

    return 0;
}