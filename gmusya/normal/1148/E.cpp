#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using ll = long long;

vi Nat(int n) {
    vi res(n);
    iota(res.begin(), res.end(), 0);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vi pa = Nat(n), pb = Nat(n);
    sort(pa.begin(), pa.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    sort(pb.begin(), pb.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    ll sum = 0;
    vector<pair<int, int>> lr;
    {
        int l = 0;
        for (int i = 0; i < n; ++i) {
            sum += b[pb[i]] - a[pa[i]];
            if (sum < 0) {
                cout << "NO\n";
                return 0;
            }
            if (sum == 0) {
                lr.emplace_back(l, i);
                l = i + 1;
            }
        }
    }
    if (sum != 0) {
        cout << "NO\n";
        return 0;
    }
    vector<pair<pair<int, int>, int>> ans;
    vector<pair<int, int>> val;
    for (int i = 0; i < n; ++i) {
        int diff = b[pb[i]] - a[pa[i]];
        if (diff > 0) {
            val.emplace_back(i, diff);
        } else {
            diff = -diff;
            while (diff) {
                ans.emplace_back(make_pair(pa[val.back().first], pa[i]), min(val.back().second, diff));
                if (val.back().second > diff) {
                    val.back().second -= diff;
                    diff = 0;
                } else {
                    diff -= val.back().second;
                    val.pop_back();
                }
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto& now : ans) {
        cout << now.first.first + 1 << ' ' << now.first.second + 1 << ' ' << now.second << '\n';
    }
    return 0;
}

/*
5
1 2 2 2 3
2 2 2 2 2
 */