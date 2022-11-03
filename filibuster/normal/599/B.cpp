#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
7 400000
0 1
0 5
0 6
1 2
1 4
2 3

*/



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> f(n), b(m);
    vector<vector<int>> c(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> f[i];
        c[f[i]].push_back(i);
    }

    bool fl1 = false, fl2 = false;
    for(int i = 0; i < m; i++) {
        cin >> b[i];

        if(c[b[i]].empty())
            fl1 = true;

        if(c[b[i]].size() > 1)
            fl2 = true;
    }

    if(fl1) {
        cout << "Impossible" << endl;
        return 0;
    }

    if(fl2) {
        cout << "Ambiguity" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    for(int i = 0; i < m; i++) {
        cout << c[b[i]][0] + 1 << ' ';
    }
}