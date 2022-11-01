#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

using ll = long long;

const ll INF = 1e18;

mt19937_64 rnd(time(nullptr));

struct SegmentTree {
    vector<int> t;
    int n;

    explicit SegmentTree(int size) {
        n = size;
        t.resize(n << 2);
        Build(1, 0, n - 1);
    }

    void Build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = tl;
            return;
        }
        int tm = (tl + tr) / 2;
        Build(v * 2, tl, tm);
        Build(v * 2 + 1, tm + 1, tr);
    }

    void Upd(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            ++t[v];
            return;
        }
        int tm = (tl + tr) / 2;
        Upd(v * 2, tl, tm, l, min(r, tm));
        Upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    int Get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }
        t[v * 2] += t[v];
        t[v * 2 + 1] += t[v];
        t[v] = 0;
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return Get(v * 2, tl, tm, pos);
        } else {
            return Get(v * 2 + 1, tm + 1, tr, pos);
        }
    }

    void Upd(int l, int r) {
        Upd(1, 0, n - 1, l, r);
    }

    int Get(int pos) {
        return Get(1, 0, n - 1, pos);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if (a < b) {
            cout << 0 << '\n';
            continue;
        }
        /*for (int i = 0; i < n; ++i) {
            a += rnd() % 26 + 'a';
            b += rnd() % 26 + 'a';
        }*/
        {
            string c = a;
            sort(c.begin(), c.end());
            if (c >= b) {
                cout << -1 << '\n';
                continue;
            }
        }
        SegmentTree segment_tree(n);
        vector<int> first_ind(26);
        vector<vector<int>> arr(26);
        for (int i = 0; i < n; ++i) {
            arr[a[i] - 'a'].push_back(i);
        }
        ll answer = INF;
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            int hm = n + 1;
            int ch = b[i] - 'a';
            for (int j = 0; j < ch; ++j) {
                if (first_ind[j] < arr[j].size()) {
                    hm = min(hm, arr[j][first_ind[j]]);
                }
            }
            if (hm != n + 1) {
                hm = segment_tree.Get(hm);
                answer = min(answer, cur + hm - i);
            }
            if (first_ind[ch] == arr[ch].size()) {
                break;
            }
            int p = arr[ch][first_ind[ch]];
            hm = segment_tree.Get(arr[ch][first_ind[ch]]);
            first_ind[ch]++;
            cur += hm - i;
            segment_tree.Upd(0, p);
        }
        cout << answer << '\n';
    }
    return 0;
}

/*
1
3
rll
rrr
 */