#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[1000105];
vector<int> v[1001005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i + 1);
    }
    ld ans = 0;
    for (int i = 1; i <= 1000000; ++i) {
        ll cur = 0;
        v[i].push_back(n + 1);
        int prv = 0;
        for (int x : v[i]) {
            ll cucur = x - prv - 1;
            cur += cucur * (cucur + 1) / 2;
            prv = x;
        }
        cur = n * ll(n + 1) / 2 - cur;
        ans += cur;
    }
    ans = ans * 2 - n;
    ans = ans / ld(n) / ld(n);
    cout << setprecision(17) << fixed << ans << endl;

    return 0;
}