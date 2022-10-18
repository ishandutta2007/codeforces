#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[100005];
map<int,int> mp;
vector<int> v,ans;

int main()
{
    cin >> n;
    if (n == 1) { cout << -1; return 0; }
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < n-1; ++i) {
        int d = a[i+1] - a[i];
        if (!mp[d]) v.push_back(d);
        ++mp[d];
    }
    if (v.size() > 2 || v.size() == 2 && mp[v[0]] > 1 && mp[v[1]] > 1) { cout << 0; return 0; }
    if (v.size() == 2) {
        int d = max(v[0], v[1]);
        int sd = v[0] + v[1] - d;
        if (sd * 2 == d && mp[d] == 1 && mp[sd] >= 1) {
            for (int i = 0; i < n-1; ++i) {
                if (a[i+1] - a[i] == d) { ans.push_back(a[i] + d / 2); break; }
            }
        }
    } else {
        if (mp[v[0]] == 1) {
            if (v[0] % 2 == 0) ans.push_back(a[0] - v[0]), ans.push_back((a[0] + a[1]) / 2), ans.push_back(a[1] + v[0]);
            else ans.push_back(a[0] - v[0]), ans.push_back(a[1] + v[0]);
        } else ans.push_back(a[0] - v[0]), ans.push_back(a[n-1] + v[0]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i + 1 < ans.size(); ++i) {
        if (ans[i] == ans[i+1]) ans.erase(ans.begin() + i), --i;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";

    return 0;
}