#include <bits/stdc++.h>
using namespace std;

int n;
string s[200105];
map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    while (n--) {
        int cur = mp[s[n]];
        ++mp[s[n]];
        if (cur == 0)
            cout << s[n] << "\n";
    }

    return 0;
}