#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int a[MAXN];
int last[MAXN];

signed main()
{
    //freopen("1.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) last[a[i]] = i;

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (last[a[i]] == i) {
            ans.push_back(a[i]);
        }
    }

    cout << ans.size() << '\n';
    for (int elem : ans) cout << elem << ' ';
    cout << '\n';

    return 0;
}