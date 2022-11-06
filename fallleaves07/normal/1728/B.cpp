#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 4) {
        printf("2 1 3 4\n");
        return;
    }
    vector<int> ans;
    vector<bool> usd(n + 1);
    ans.push_back(n);
    ans.push_back(n - 1);
    usd[n - 1] = usd[n] = true;
    if (n % 2 == 1) {
        for (int i = 2; i < n - 1; i++) {
            ans.push_back(i);
        }
        ans.push_back(1);
    } else {
        for (int i = 1; i < n - 1; i++) {
            ans.push_back(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto v : ans) {
        printf("%d ", v);
    }
    puts("");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}