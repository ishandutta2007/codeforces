#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 1e6 + 13;
const int K = 113;

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

bool unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return false;

    if(sz[x] < sz[y])
        swap(x, y);

    sz[x] += sz[y];
    p[y] = x;

    return true;
}

/*
1
3 2
1 13 1
*/

pii e[N];

void solve() {
    int n, d;
    cin >> n >> d;


    for(int i = 0; i < d; i++) {
        cin >> e[i].f >> e[i].s;

        e[i].f--;
        e[i].s--;
    }

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    int mx = 1;
    int cnt = 0;

    for(int i = 0; i < d; i++) {
        int x = e[i].f, y = e[i].s;

//        unite(x, y);

        if(!unite(x, y)) {
            cnt++;
        }

        int res = 0;

        vector<pii> a;
        for(int j = 0; j < n; j++) {
            if(p[j] == j) {
                a.emplace_back(sz[j], j);
            }
        }

        sort(a.rbegin(), a.rend());

        for(int j = 0; j < a.size() && j <= cnt; j++) {
            res += a[j].f;
        }

        cout << res - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}