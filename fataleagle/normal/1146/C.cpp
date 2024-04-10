#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < 9; i++)
    {
        vector<int> a, b;
        for (int j = 0; j < n; j++)
        {
            if ((j >> i) & 1)
            {
                a.push_back(j);
            }
            else
            {
                b.push_back(j);
            }
        }
        if (a.empty() || b.empty())
        {
            continue;
        }
        cout << a.size() << ' ' << b.size();
        for (auto it: a)
        {
            cout << ' ' << it + 1;
        }
        for (auto it: b)
        {
            cout << ' ' << it + 1;
        }
        cout << endl;
        int x;
        cin >> x;
        if (x == -1)
        {
            exit(0);
        }
        ans = max(ans, x);
    }
    cout << "-1 " << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}