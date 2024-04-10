#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int m,t,r,a[1005],ans;
map<int,int> mp;

int main()
{
    cin >> m >> t >> r;
    if (t < r) { cout << -1; return 0; }
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(a,a+m);
    for (int i = m-1; i >= 0; --i) {
        int cnt = 0;
        for (int j = t; j >= 1; --j)
            cnt += mp[a[i]-j];
        cnt = r - cnt;
        for (int j = t; j >= 1 && cnt > 0; --j)
            if (!mp[a[i]-j]) mp[a[i]-j] = 1, --cnt, ++ans;
    }
    cout << ans;
    return 0;
}