#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int K = 10;

/*
*/


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> a(n, {0, 0}), b(m, {0, 0});
    for(int i = 0; i < k; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        x--;
//        y--;

        if(t == 1) {
            a[x] = {y, i + 1};
        } else {
            b[x] = {y, i + 1};
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (a[i].s > b[j].s ? a[i].f : b[j].f) << ' ';
        }

        cout << endl;
    }
}