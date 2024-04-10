#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105], u[100105];
vector< vector<int> > ans;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
        cin >> a[i], mp[a[i]] = 1;
    int idx = 0;
    for (pii x : mp) {
        if (x.second)
            mp[x.first] = idx++;
    }
    for (int i = 0; i < n; ++i)
        a[i] = mp[a[i]];
    for (int i = 0; i < n; ++i) {
        if (u[i]) continue;
        vector<int> curv;
        int cur = i;
        while (!u[cur]) {
            u[cur] = 1;
            curv.push_back(cur);
            cur = a[cur];
        }
        sort(curv.begin(), curv.end());
        ans.push_back(curv);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); ++j)
            cout << " " << ans[i][j] + 1;
        cout << "\n";
    }


    return 0;
}