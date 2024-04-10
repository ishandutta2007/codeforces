#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
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
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> f(26, 0);
        for (int i = 0; i < s.size(); i++) f[s[i] - 'a']++;
        string ans = "-1";
        for (int i = n - 1; i >= -1; i--)
        {
            int sum = 0;
            for (int j = 0; j < 26; j++) sum += (k - f[j] % k) % k;
            if (sum <= (n - i - 1) && sum % k == (n - i - 1) % k)
            {
                if (i == n - 1)
                {
                    ans = s;
                    break;
                }
                vector<int> f2(26, 0);
                for (int j = 0; j < 26; j++) f2[j] = (k - f[j] % k) % k;
                char c = '.';
                for (char j = s[i + 1] + 1; j <= 'z'; j++)
                {
                    if (f2[j - 'a'])
                    {
                        f2[j - 'a']--; 
                        c = j;
                        break;
                    }
                    if (sum < (n - i - 1))
                    {
                        f2[j - 'a'] += k - 1, sum += k;
                        c = j;
                        break;
                    }
                }
                if (c != '.')
                {
                    ans = s.substr(0, i + 1);
                    ans.push_back(c);
                    f2[0] += (n - i - 1) - sum;
                    for (int j = 0; j < 26; j++) ans += string(f2[j], j + 'a');
                    break;
                }
            }
            if (i >= 0) f[s[i] - 'a']--;
        }
        cout << ans << "\n";
    }
    return 0;
}