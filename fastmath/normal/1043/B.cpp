#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int n;            
int a[MAXN];
void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int t[MAXN];
int tmp[MAXN];
bool check(int len) {
    t[0] = a[0];
    for (int i = 1; i < len; ++i) t[i] = a[i] - a[i - 1];
    tmp[0] = a[0];
    for (int i = 1; i < n; ++i) tmp[i] = tmp[i - 1] + t[i % len];
    for (int i = 0; i < n; ++i) if (tmp[i] != a[i]) return 0;
    return 1;
}   

vector <int> ans;
void solve() {
    for (int len = 1; len <= n; ++len) {
        if (check(len)) ans.push_back(len);
    }   
}

void print() {
    cout << ans.size() << '\n';
    for (int e : ans) cout << e << ' ';
    cout << '\n';
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}