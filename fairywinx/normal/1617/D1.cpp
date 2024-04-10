#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

map<array<int, 3>, int> tmp;
int q;
int n;

int ask(int a, int b, int c) {
    if (tmp.count({a, b, c}))
        return tmp[{a, b, c}];
    assert(a != b && a != c && c != b);
    ++q;
    if (q > 2 * n)
        exit(1);
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int res;
    cin >> res;
    return tmp[{a, b, c}] = res;
}

void solve() {
    array<int, 2> pos = {-1, -1};
    cin >> n;
    q = 0;
    tmp.clear();
    for (int i = 1; i <= n - 2; i += 3) {
        pos[ask(i, i + 1, i + 2)] = i;
    }
    int pos_pr = -1;
    int tmp1 = -1, tmp2 = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            bool find = false;
            for (int k = 0; k < 2; ++k) {
                if (ask(pos[0] + i, pos[0] + j, pos[1] + k) == 1) {
                    find = 1;
                    break;
                }
            }
            if (!find) {
                tmp1 = pos[0] + j;
                pos_pr = pos[0] + i;
                break;
            }
        }
    }

    int pos_d = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            bool find = false;
            if (ask(pos[1] + i, pos[1] + j, pos_pr) == 0) {
                find = 1;
            }
            if (!find) {
                tmp2 = pos[1] + j;
                pos_d = pos[1] + i;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(pos_pr);
    ans.push_back(tmp1);
    for (int i = 1; i <= n; ++i) {
        if (i == pos_d || i == pos_pr || i == tmp1 || i == tmp2)
            continue;
        if (ask(i, pos_d, pos_pr) == 0)
            ans.push_back(i);
    }
    cout << "! " << ans.size() << ' ';
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}