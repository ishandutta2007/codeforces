#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, qr;
    cin >> n >> qr;
    int cnt1 = 0;
    int cnt = 0;
    set <pair <int, int>> q;
    vector <set <int>> id(n);
    for (int i = 0; i < qr; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;
            q.insert({cnt, x});
            id[x].insert(cnt);
            ++cnt;
        }
        else if (t == 2) {
            int x;
            cin >> x;
            --x;
            for (auto j : id[x]) {
                q.erase({j, x});
            }
            cnt1 += (int)id[x].size();
            id[x].clear();
        }
        else {
            int t;
            cin >> t;
            while (!q.empty() && q.begin()->first < t) {
                auto p = *q.begin();
                q.erase(q.begin());
                id[p.second].erase(p.first);
                ++cnt1;
            }
        }
        cout << cnt - cnt1 << '\n';
    }
}