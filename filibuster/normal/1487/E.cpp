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
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

mt19937 rnd(5443);

int n[4];
int a[4][N];
int dp[4][N];
vector<int> g[4][N];
set<int> st[4][N];

int main() {
    for(int i = 0; i < 4;i++) {
        cin >> n[i];
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            dp[i][j] = INF;
        }
    }

    for(int i = 1; i < 4; i++) {
        int m;
        cin >> m;
        for(int j = 0; j < m;j++) {
            int x, y;
            cin >>x >> y;

            x--;
            y--;

            g[i][y].push_back(x);
            st[i][y].insert(x);
        }
    }

    vector<pii> b(n[0]);

    for(int i = 0; i < n[0]; i++) {
        dp[0][i] = a[0][i];
        b[i] = {dp[0][i], i};
//        cout << 0 << ' ' << i << ' ' << dp[0][i] << endl;
    }

    sort(b.begin(), b.end());

    for(int i = 1; i < 4; i++) {
//        cout << "b  " << b.size() << endl;
        for(int j = 0; j < n[i]; j++) {
            for(int k = 0; k < b.size(); k++) {
//                cout << st[i][j].count(b[k].s) << endl;
                if(st[i][j].count(b[k].s) == 0) {
                    dp[i][j] = a[i][j] + b[k].f;
                    break;
                }
            }
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }

        b.erase(b.begin(), b.end());
        b.resize(n[i]);

        for(int j = 0; j < n[i]; j++) {
            b[j] = {dp[i][j], j};
        }
        sort(b.begin(), b.end());
//        for(int j = 0; j < n[i]; j++) {
//            cout << b[j].f << ' ' << b[j].s << endl;
//        }
    }

    cout << (b[0].f < INF ? b[0].f : -1) << endl;
}