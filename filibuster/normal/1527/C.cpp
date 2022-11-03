#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 998244353;
const int N = 3013;

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        mp[x].push_back(i);
    }

    li ans = 0;

    for(auto p : mp) {
        vector<int> a = p.s;

        li sum = 0;
        for(int i = 0; i < a.size(); i++) {
            ans += sum * (n - a[i]);
            sum += a[i] + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}