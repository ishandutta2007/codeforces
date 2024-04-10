#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i <= n; ++i){
        int ost = n - a * i;
        if (ost < 0) break;
        if (ost % b == 0){
            cout << "YES\n";
            cout << i << ' ' << ost / b << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}