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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int p = 1; p <= n / 2; p++) {
        if(2 * p != n) {
            for(int i = 0; i < n; i++) {
                int j = (i + p) % n;
                a[i][j] = 1;
                a[j][i] = -1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << a[i][j] << ' ';
        }
    }

    cout << endl;
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}