#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, y, u[105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x;
    while (n--) {
        cin >> y;
        u[y] = 1;
    }
    int ans = !!u[x];
    for (int i = 0; i < x; ++i)
        ans += !u[i];
    cout << ans << endl;

    return 0;
}