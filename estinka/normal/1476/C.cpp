#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll>c(n), a(n), b(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        set<ll> best;
        ll add = 0, ans = 0;
        for (int i = 1; i < n; i++)
        {
            add += c[i - 1] - abs(a[i] - b[i]) + 1;
            if (a[i] == b[i])
            {
                best.clear();
                add = 0;
                best.insert(abs(a[i] - b[i]) + 1);
            }
            else
            {
                best.insert(abs(a[i] - b[i]) + 1 - add);
            }
            //cout << "           " << c[i] + add + *prev(best.end()) << "\n";
            ans = max(ans, c[i] + add + *prev(best.end()));
        }
        //cout << "               ";
        cout << ans << "\n";
    }
    return 0;
}