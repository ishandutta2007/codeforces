#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, a[10005], x, y, z;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (m--) {
        cin >> x >> y >> z;
        int cnt = 0;
        for (int i = x; i <= y; ++i)
            cnt += a[i] < a[z];
        cout << (cnt == z - x ? "Yes" : "No") << "\n";
    }

    return 0;
}