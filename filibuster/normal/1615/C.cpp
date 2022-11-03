#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
1
2
11
00
*/


int bfs(vector<vector<int>> v) {
    queue<vector<vector<int>>> q;
    map<vector<vector<int>>, int> dp;

    q.push(v);
    dp[v] = 0;

    while(!q.empty()) {
        auto cnt = q.front();
        q.pop();

        if(cnt[0][1] == 0 && cnt[1][0] == 0)
            return dp[cnt];

        if(cnt[1][0] > 0) {
            auto cnt1 = cnt;
            cnt1[1][0]--;
            swap(cnt1[0][1], cnt1[1][1]);
            swap(cnt1[1][0], cnt1[0][0]);
            cnt1[1][0]++;

            if(dp.count(cnt1) == 0) {
                q.push(cnt1);
                dp[cnt1] = dp[cnt] + 1;
            }
        }

        if(cnt[1][1] > 0) {
            auto cnt1 = cnt;
            cnt1[1][1]--;
            swap(cnt1[0][1], cnt1[1][1]);
            swap(cnt1[1][0], cnt1[0][0]);
            cnt1[1][1]++;

            if(dp.count(cnt1) == 0) {
                q.push(cnt1);
                dp[cnt1] = dp[cnt] + 1;
            }
        }

    }
    return -1;
}

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> cnt(2, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        cnt[a[i] - '0'][b[i] - '0']++;
    }

//    dp.erase(dp.begin(), dp.end());

    int res = bfs(cnt);
    cout << res << endl;

//    cout << (res < INF ? res : -1) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
//
    while(t--)
        solve();
}