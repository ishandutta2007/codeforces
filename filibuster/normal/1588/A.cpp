//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;


/*
*/

void solve() {
    int n;
    cin >> n;

    map<int, int> ma, mb;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ma[x]++;
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        mb[x]++;
    }

    bool res = true;
    for(auto p : ma) {
        if(mb[p.f] > p.s || mb[p.f] + mb[p.f + 1] < p.s) {
            res = false;
            break;
        }

        mb[p.f + 1] -= p.s - mb[p.f];
    }

    cout << (res ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}