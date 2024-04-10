#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

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
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}