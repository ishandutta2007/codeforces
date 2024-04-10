#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> l(n), b;
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
            if (l[i] == 0)
            {
                b.push_back(a[i]);
            }
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            if (l[i] == 0)
            {
                a[i] = b.back();
                b.pop_back();
            }
        }
        for (auto &x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}