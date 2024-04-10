#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 1e6 + 13;
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> p(2 * n);
    for(int i = 0; i < n * 2; i++) {
        cin >> p[i];
    }

    vector<int> a;
    for(int i = 0; i < n * 2; i++) {
        int cnt = 1;
        for(int j = i + 1; j < n * 2 && p[j] < p[i]; j++) {
            cnt++;
        }

        a.push_back(cnt);
        i += cnt - 1;
    }

//    cout << "dff" << endl;

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for(int i = 0; i < a.size(); i++) {
//        cout << i << endl;
        for(int j = n; j >= 0; j--) {
            if(dp[j] && a[i] + j < dp.size()) {
                dp[j + a[i]] = true;
            }
        }
    }

    cout << (dp[n] ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}