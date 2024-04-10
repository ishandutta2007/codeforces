#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m;
char s[99][99];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m-1; ++j) {
            map<char,int> mp,mp2;
            ++mp[s[i][j]];
            ++mp[s[i][j+1]];
            ++mp[s[i+1][j]];
            ++mp[s[i+1][j+1]];

            ++mp2['f'];
            ++mp2['a'];
            ++mp2['c'];
            ++mp2['e'];

            if (mp == mp2) ++ans;
        }
    }
    cout << ans;


    return 0;
}