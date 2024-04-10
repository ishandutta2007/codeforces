#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
#include <bitset>
typedef long long ll;
using namespace std;

int val(string& s)
{
    int ans = 0, len = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            ans = max(ans, len);
            len = 1;
        }
        else len++;
    }
    ans = max(ans, len);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = val(s);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            string s1;
            for (int j = i - 1; j >= 0; j--) s1.push_back(s[j]);
            for (int j = s.size() - 1; j >= i; j--) s1.push_back(s[j]);
            ans = max(val(s1), ans);
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}