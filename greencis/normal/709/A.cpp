#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, b, d, x, cur, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> b >> d;
    while (n--) {
        cin >> x;
        if (b >= x) {
            cur += x;
            if (cur > d) {
                cur = 0;
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}