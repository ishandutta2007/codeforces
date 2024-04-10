#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
int a[MAXN], w[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i]);
    }   

    for (int i = 0; i < n; ++i) {
        w[i] = mx - a[i];
    }   
    
    vector <int> v;
    for (int i = 0; i < n; ++i) {
        if (v.empty()) {
            v.push_back(w[i]);
        }   
        else if (v.back() < w[i]) {
            v.push_back(w[i]);
        }   
        else if (w[i] < v.back()) {
            cout << "NO\n";
            exit(0);
        }   
        else if (w[i] == v.back()) {
            v.pop_back();
        }   
    }   

    int sum = 0;
    for (auto e : v) {
        sum += e;
    }

    if (sum == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}