#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
const int N = (int)1e6;
vector<int> lst[N];
int a[N], b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        lst[a[i]].push_back(b[i]);
    }
    int cnt = k;
    vector<int> tmp;
    for (int i = 1; i <= k; i++) {
        if (lst[i].empty()) continue;
        sort(lst[i].begin(), lst[i].end());
        cnt--;
        for (int j = 0; j + 1 < lst[i].size(); j++) {
            tmp.push_back(lst[i][j]);
        }
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < cnt; i++) {
        ans += tmp[i];
    }
    cout << ans << "\n";
    return 0;
}