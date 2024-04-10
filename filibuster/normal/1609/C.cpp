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

int d[N];
vector<int> a[N];

/*
1
3 2
1 13 1
*/

void solve() {
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++) {
        a[i].erase(a[i].begin(), a[i].end());
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a[i % e].push_back(x);
    }

    li ans = 0;

    for(int i = 0; i < e; i++) {
        vector<int>& b = a[i];

        vector<int> lf(b.size(), -1);
        vector<int> rg(b.size(), b.size());
        int lst = -1;
        for(int j = 0; j < b.size(); j++) {
            lf[j] = lst;
            if(b[j] != 1)
                lst = j;
        }

        lst = b.size();
        for(int j = b.size() - 1; j >= 0; j--) {
            rg[j] = lst;
            if(b[j] != 1)
                lst = j;
        }

        for(int j = 0; j < b.size(); j++) {
            if(b[j] != 1 && d[b[j]] == 0) {
                ans += (j - lf[j]) * 1ll * (rg[j] - j) - 1;
            }
        }
//        cout << i << ' ' << ans << endl;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}