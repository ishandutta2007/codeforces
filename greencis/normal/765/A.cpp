#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
string s;
map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ++mp[s.substr(0, 3)];
        ++mp[s.substr(5, 3)];
    }
    int z = 0;
    for (auto it : mp) {
        if (it.second % 2 != 0 && !z)
            cout << "contest", z = 1;
    }
    if (!z)
        cout << "home";

    return 0;
}