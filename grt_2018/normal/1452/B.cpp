#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

int t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vi a(n);
        ll sum = 0, cur = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        cur = sum;
        for(int i = 0; i < n; ++i) {
            cur = max(cur, 1LL * a[i] * (n - 1));
        }
        //cout << cur << " ";
        if(cur % (n - 1) != 0) cur += (n - 1) - (cur % (n - 1));
        cout << cur - sum << "\n";
    }

}