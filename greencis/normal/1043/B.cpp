#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[1005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n - 1; i > 0; --i)
        a[i] -= a[i - 1];
    vector<int> ans;
    for (int len = 1; len <= n; ++len) {
        int ok = 1;
        for (int i = 0; i < n; ++i)
            ok &= (a[i] == a[i % len]);
        if (ok)
            ans.push_back(len);
    }
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";

}