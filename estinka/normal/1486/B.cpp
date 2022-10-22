#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <array>
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
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        if (n % 2 == 1)
        {
            cout << "1\n";
            continue;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int mid = n / 2 - 1;
        //cout << "           ";
        cout << (x[mid + 1] - x[mid] + 1ll) * (y[mid + 1] - y[mid] + 1ll) << "\n";
    }
    return 0;
}