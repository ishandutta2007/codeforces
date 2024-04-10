#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<int> pr, lp;
vector<int> num_p;
vector<int> cnt;
vector<int> arr;

const int MAX_N = 1e6 + 1;

void init() {
    lp.resize(MAX_N);
    num_p.resize(MAX_N);
    cnt.resize(MAX_N);
    for (int i = 2; i < MAX_N; ++i) {
        if (!lp[i]) {
            pr.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && pr[j] * i < MAX_N; ++j) {
            lp[pr[j] * i] = pr[j];
        }
    }
    arr.resize(MAX_N, 2);
    arr[1] = 0;
    for (int x : pr) {
        arr[x] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(e);
        for (int i = 0; i < n; ++i) {
            b[i % e].push_back(arr[a[i]]);
        }
        ll ans = 0;
        for (auto& now : b) {
            int m = (int) now.size();
            for (int i = 1; i < m; ++i) {
                now[i] += now[i - 1];
            }
            for (int i = 0; i < m; ++i) {
                if (now[i] == (i ? now[i - 1] : 0) + 1) {
                    --ans;
                }
                ans += upper_bound(now.begin(), now.end(), (i ? now[i - 1] : 0) + 1) - lower_bound(now.begin(), now.end(), (i ? now[i - 1] : 0) + 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}