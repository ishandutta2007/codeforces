#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

map<int,int> mp, mp2;
map<pair<int,int>, int> mp3;
ll ans;
int n, x, y;

int main()
{
    cin >> n;
    while (n--) {
        cin >> x >> y;
        ++mp[x];
        ++mp2[y];
        ++mp3[make_pair(x, y)];
    }
    for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        ans += ll(it->second) * ll(it->second - 1) / 2LL;
    }
    for (map<int,int>::iterator it = mp2.begin(); it != mp2.end(); ++it) {
        ans += ll(it->second) * ll(it->second - 1) / 2LL;
    }
    for (map<pair<int,int>, int>::iterator it = mp3.begin(); it != mp3.end(); ++it) {
        ans -= ll(it->second) * ll(it->second - 1) / 2LL;
    }
    cout << ans;

    return 0;
}