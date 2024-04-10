#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

vector <int> a;

bool want[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int k, n, m;
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i){
        want[i] = true;
    }

    int j = 0;
    int bal = 0;
    for (int i = 0; i < n; ++i){
        bal++;
        while (m <= a[i] - a[j]){
            bal -= want[j];
            ++j;
        }

        if (bal == k){
            want[i] = false;
            --bal;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans += !want[i];
    }
    cout << ans;

    return 0;
}