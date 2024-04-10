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
        vector<vector<int> > s(n, vector<int>(5));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++) cin >> s[i][j];
        }
        bool ok = false;
        for (int a = 0; a < 5; a++) for (int b = a + 1; b < 5; b++)
        {
            int ca = 0, cb = 0;
            bool none = false;
            for (int i = 0; i < n; i++)
            {
                if (s[i][a]) ca++;
                if (s[i][b]) cb++;
                if (!s[i][a] && !s[i][b]) none = true;
            }
            if (!none && ca >= n / 2 && cb >= n / 2)
            {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}