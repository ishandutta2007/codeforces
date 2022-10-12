#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e6+5;
int a[N], v[N];
vector<int> f[N];
array<int, 2> diff[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], f[a[i]].pb(i+1);
    int p = -1;
    for (int i = 0; i < N; i++) {
        if (f[i].size() >= 4) {
            cout << "YES\n";
            for (int j = 0; j < 4; j++)
                cout << f[i][j] << " \n"[j == 3];
            exit(0);
        }
        if (f[i].size() >= 2) {
            if (p == -1) p = i;
            else {
                cout << "YES\n";
                cout << f[p][0] << " " << f[i][0] << " ";
                cout << f[p][1] << " " << f[i][1] << "\n";
                exit(0);
            }
        }
    }
    if (p != -1) {
        for (int i = 0; i < p; i++)
            if (2*p-i < N && f[i].size() && f[2*p-i].size()) {
                cout << "YES\n";
                cout << f[p][0] << " " << f[p][1] << " ";
                cout << f[i][0] << " " << f[2*p-i][0] << "\n";
                exit(0);
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            int d = abs(a[i]-a[j]);
            auto [x, y] = diff[d];
            int w = i, z = j;
            if (a[x] > a[y]) swap(x, y);
            if (a[w] > a[z]) swap(w, z);
            if (v[d] && i != x && j != x && i != y && j != y) {
                cout << "YES\n";
                cout << x+1 << " " << z+1 << " "; 
                cout << y+1 << " " << w+1 << "\n";
                exit(0);
            }
            if (!v[d]) diff[d] = {i, j}, v[d] = 1;
        }
    cout << "NO\n";
}