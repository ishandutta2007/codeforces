#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector<int> nxt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nxt[a[i]].push_back(i);
    }

    for (int i = 0; i <= n; i++) {
        nxt[i].push_back(n);
    }

    int s = 0, t = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s == a[i] || t == a[i]) continue;

        ans++;

        int s_nxt = *upper_bound(nxt[s].begin(), nxt[s].end(), i);
        int t_nxt = *upper_bound(nxt[t].begin(), nxt[t].end(), i);
        if (s_nxt < t_nxt) t = a[i];
        else s = a[i];
    }

    cout << ans;
}