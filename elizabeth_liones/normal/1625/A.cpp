#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l;
        cin >> n >> l;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            int one = 0;
            for (int j = 0; j < n; j++) if (x[j] & (1 << i)) one++;
            if (one > n - one) ans += (1 << i);
        }
        cout << ans << "\n";
    }
    return 0;
}