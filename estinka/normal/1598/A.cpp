#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
        string a, b;
        cin >> a >> b;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1' && b[i] == '1') ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}