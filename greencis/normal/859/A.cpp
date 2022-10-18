#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);

    int n, x, ans = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        ans = max(ans, max(x - 25, 0));
    }
    cout << ans << endl;

    return 0;
}