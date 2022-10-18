#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a,ans = 1;
map<int,int> mp;

int main()
{
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&a);
        if (a == 1) continue;
        int cur = 0;
        for (int j = 1; j * j <= a; ++j) {
            if (a % j) continue;
            cur = max(cur, max(mp[j], mp[a / j]));
        }
        ++cur;
        ans = max(ans, cur);
        for (int j = 1; j * j <= a; ++j) {
            if (a % j) continue;
            if (j > 1) mp[j] = max(mp[j], cur);
            if (j * j < a) mp[a/j] = max(mp[a/j], cur);
        }
    }
    cout << ans;

    return 0;
}