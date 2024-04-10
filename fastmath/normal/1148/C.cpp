#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define i first
#define j second
#define push push_back
const int N = 3e5 + 7;
int p[N];
int pos[N];
vector <ii> ans;
void f(int i, int j) {
    ans.push({i, j});
    swap(pos[p[i]], pos[p[j]]);
    swap(p[i], p[j]);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int m = n >> 1;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int x = pos[i];
        if (x == i) {
            continue;
        }   
        else if (x <= m) {
            f(x, n);
            f(i, n);
        }   
        else if (i <= m && x > m) {
            f(1, x);
            f(1, n);
            f(i, n);
            if (i == 1) continue;
            f(1, n);
            f(1, x);
        }   
        else if (i > m) {
            f(1, x);
            f(1, i);
            f(1, x);
        }
        else {
            exit(1);
        }   
    }   
    cout << ans.size() << '\n';
    for (auto e : ans) cout << e.i << ' ' << e.j << '\n';
}