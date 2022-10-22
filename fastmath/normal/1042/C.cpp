#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int a[MAXN];
int pr[MAXN];
bool used[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += (a[i] < 0);

    vector <int> v, nv;
    if (cnt % 2 == 1) {
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (0 <= a[i]) continue;
            if (mx == -1 || a[mx] < a[i]) mx = i;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) nv.push_back(i);
        }
        nv.push_back(mx);
        sort(nv.begin(), nv.end());
        for (int i = 0; i < (int)nv.size() - 1; ++i) {
            cout << "1 " << nv[i] + 1 << ' ' << nv[i + 1] + 1 << '\n';
            used[nv[i]] = 1;
        }
        if ((int)nv.size() == n) exit(0);
        used[nv.back()] = 1;
        cout << "2 " << nv.back() + 1 << '\n';
        for (int i = 0; i < n; ++i) if (!used[i]) v.push_back(i);
        for (int i = 0; i < (int)v.size() - 1; ++i) {
            cout << "1 " << v[i] + 1 << ' ' << v[i + 1] + 1 << '\n';
        }   
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) nv.push_back(i);
        }   
        if (nv.empty()) {
            for (int i = 0; i < n - 1; ++i) cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
            exit(0);
        }
        for (int i = 0; i < (int)nv.size() - 1; ++i) {
            cout << "1 " << nv[i] + 1 << ' ' << nv[i + 1] + 1 << '\n';
            used[nv[i]] = 1;
        }
        if ((int)nv.size() == n) exit(0);
        used[nv.back()] = 1;
        cout << "2 " << nv.back() + 1 << '\n';
        for (int i = 0; i < n; ++i) if (!used[i]) v.push_back(i);
        for (int i = 0; i < (int)v.size() - 1; ++i) {
            cout << "1 " << v[i] + 1 << ' ' << v[i + 1] + 1 << '\n';
        }           
    }

    return 0;
}