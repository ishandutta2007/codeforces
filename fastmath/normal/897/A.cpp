#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

char a[2007];

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i){
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        --l;
        --r;
        for (int j = l; j <= r; ++j){
            if (a[j] == c1) a[j] = c2;
        }
    }

    for (int i = 0; i < n; ++i){
        cout << a[i];
    }

    return 0;
}