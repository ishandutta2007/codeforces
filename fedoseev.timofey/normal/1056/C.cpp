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
    int n, m;
    cin >> n >> m;
    vector <int> p(2 * n);
    vector <int> used(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> p[i];
    vector <pair <int, int>> pr(m);
    for (int i = 0; i < m; ++i) {
        cin >> pr[i].first >> pr[i].second;
        --pr[i].first;
        --pr[i].second;
        if (p[pr[i].first] < p[pr[i].second]) swap(pr[i].first, pr[i].second);
    }
    int t;
    cin >> t;
    --t;
    int lst = -1;
    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2 == t) {
            bool fnd = false;
            for (int j = 0; j < m; ++j) {
                if (pr[j].first == lst) {
                    if (!used[pr[j].second]) {
                        used[pr[j].second] = 1;
                        cout << pr[j].second + 1 << endl;
                        fnd = true;
                        break;
                    }
                }
                if (pr[j].second == lst) {
                    if (!used[pr[j].first]) {
                        used[pr[j].first] = 1;
                        cout << pr[j].first + 1 << endl;
                        fnd = true;
                        break;
                    }
                }
            }
            if (fnd) continue;
            int bst = -1;
            for (int j = 0; j < m; ++j) {
                if (!used[pr[j].first] && !used[pr[j].second]) {
                    if (bst == -1) bst = j;
                }
            }
            if (bst != -1) {
                used[pr[bst].first] = 1;
                cout << pr[bst].first + 1 << endl;
            }
            else {
                for (int j = 0; j < 2 * n; ++j) {
                    if (!used[j]) {
                        if (bst == -1 || p[j] > p[bst]) {
                            bst = j;
                        }
                    }
                }
                used[bst] = 1;
                cout << bst + 1 << endl;
            }
        }
        else {
            int x;
            cin >> x;
            --x;
            lst = x;
            used[x] = 1;
        }
    }
}