#include <iostream>
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
        int n;
        string s;
        cin >> n >> s;
        int ans = 1e9;
        for (int i = 0; i < 26; i++)
        {
            int l = 0, r = n - 1;
            int e = 0;
            while (l <= r)
            {
                if (s[l] != s[r])
                {
                    e++;
                    if (s[l] - 'a' == i) l++;
                    else if (s[r] - 'a' == i) r--;
                    else
                    {
                        e = 1e9;
                        break;
                    }
                    continue;
                }
                if (s[l] == s[r]) l++, r--;
            }
            ans = min(ans, e);
        }
        cout << (ans > n ? -1 : ans) << "\n";
    }
    return 0; 
}