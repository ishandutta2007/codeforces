#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld float
#define all(a) (a).begin(), (a).end()

const int inf = 1e9 + 7;

const int mxn = 1e4 + 40;

ld pw[mxn];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int C = 1e10;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> mst(n);

    for (int i = 0; i < mxn; i++) {
        pw[i] = pow(1.3, -i);
    }


    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        

        ld c[2];
        c[0] = 0;
        c[1] = 0;
        int mn = inf;
        for (int j = 0; j < n; j++) {
            mn = min(mn, mst[j]);
        }

        for (int j = 0; j < n; j++) {
            c[s[j] - '0'] += pw[mst[j] - mn];
        }

        ld x = (ld)(rng() % C)/C;

        if (x < c[0] / (c[0] + c[1])) {
            cout << "0" << endl;
        } else {
            cout << "1" << endl;
        }

        char ans;
        cin >> ans;

        for (int j = 0; j < n; j++) {
            mst[j] += (s[j] != ans);
        }
    }
    return 0;
}