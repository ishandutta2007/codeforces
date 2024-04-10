#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int d = 700;
ll ans[710][710];
ll a[500010];
int main() {
    ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if(opt == 1) {
            a[x] += y;
            for(int i = 1; i <= d; i++) ans[i][x % i] += y;
        }
        else {
            if(x <= d) cout << ans[x][y] << endl;
            else {
                ll answ = 0;
                for(int j = y; j <= 500000; j += x) answ += a[j];
                cout << answ << endl;
            }
        }
    }
}