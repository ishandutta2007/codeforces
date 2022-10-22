#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
        sort(a.begin(), a.end(), greater<pair<int, int> >());
        vector<int> ans(n + 1);
        ans[0] = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1) ans[a[i].second] = -(i + 1) / 2;
            else ans[a[i].second] = (i + 2) / 2;
            sum += abs(ans[a[i].second]) * 2ll * a[i].first;
        }
        cout << sum << "\n";
        for (int i = 0; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}