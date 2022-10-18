#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m[1005];
map<string,int> mp;
string s[1005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> m[i];
        mp[s[i]] += m[i];
    }
    int mx = -2e9;
    map<string,int> winners;
    for (map<string,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        if (it->first.size()) {
            int num = it->second;
            if (num > mx) mx = num, winners.clear();
            if (num == mx) winners[it->first] = 1;
        }
    }
    mp.clear();
    for (int i = 0; i < n; ++i) {
        mp[s[i]] += m[i];
        if (mp[s[i]] >= mx && winners[s[i]]) {
            cout << s[i];
            return 0;
        }
    }
    return 0;
}