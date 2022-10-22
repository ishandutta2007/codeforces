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
        map<int, int> f;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            f[x]++;
        }
        int com = 0;
        while (f[com] >= 2)
        {
            com++;
        }
        int extra = com;
        while (f[extra] >= 1)
        {
            extra++;
        }
        cout << com + extra << "\n";
    }
}