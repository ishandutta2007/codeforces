#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n;
int a[MAXN];
int pref[MAXN], post[MAXN];
int prefmx[MAXN], postmx[MAXN];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
        prefmx[i + 1] = max(prefmx[i], a[i]);
    }   

    for (int i = n - 1; i >= 0; --i) {
        post[i] = post[i + 1] + a[i];
        postmx[i] = max(postmx[i + 1], a[i]);   
    }

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        int mx = max(prefmx[i], postmx[i + 1]);
        int sum = pref[i] + post[i + 1];
        if (mx * 2 == sum) ans.push_back(i);
    }
    
    cout << ans.size() << '\n';
    for (int e : ans) cout << e + 1 << ' ';
    cout << '\n';

    return 0;
}