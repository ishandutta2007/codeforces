//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*
1
8 5
2 1 7 4
4 2

*/

//void solve() {
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n, m;
    cin >> n >> m;

    vector<int> cur(n, 0);
    int cnt = n;

    for(int ind = 0; ind < m; ind++) {
        int v, u;
        cin >> v >> u;


        v--;
        u--;

        if(v > u)
            swap(v, u);

        cur[v]++;
        if(cur[v] == 1)
            cnt--;

    }

    int q;
    cin >> q;

    for(int ind = 0; ind < q; ind++) {
        int t;
        cin >> t;

        if(t == 1) {
            int v, u;
            cin >> v >> u;


            v--;
            u--;

            if(v > u)
                swap(v, u);

            cur[v]++;
            if(cur[v] == 1)
                cnt--;
        } else if(t == 2) {
            int v, u;
            cin >> v >> u;


            v--;
            u--;

            if(v > u)
                swap(v, u);

            cur[v]--;
            if(cur[v] == 0)
                cnt++;
        } else {
            cout << cnt << '\n';
        }


    }
}