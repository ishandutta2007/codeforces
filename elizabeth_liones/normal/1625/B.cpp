#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
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
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, vector<int> > m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]].push_back(i);
        }
        int ans = -1;
        for (auto i : m)
        {
            vector<int> v = i.second;
            for (int j = 0; j + 1 < v.size(); j++)
            {
                ans = max(ans, v[j] + n - v[j + 1]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}