#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,ans;
string s[105];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int l = 0, r = 0;
    for (int i = 0; i < m; ++i) {
        bool good = true;
        for (int j = 0; j < n-1; ++j)
            if (s[j].substr(l,r-l+1) > s[j+1].substr(l,r-l+1)) { good = false; break; }
        if (good) ++r;
        else {
            ++ans;
            for (int j = 0; j < n; ++j)
                s[j].erase(r,1);
        }
    }
    cout << ans;
    return 0;
}