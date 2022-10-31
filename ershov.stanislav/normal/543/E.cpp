#include <bits/stdc++.h>

#define fs first
#define sc second

using namespace std;

const int INF = 1e9;
const int N = 2e5 + 100;
const int MAGIC1 = 400;
const int MAGIC2 = 400;

int tree[N * 4], tree_add[N * 4];
int n, m, s;
int songs[N];
vector<pair<int, int> > sorted;
vector<vector<int> > places, first, mn;
pair<int, int> add[N];

int get(int v, int vl, int vr, int l, int r) {
    if (vl >= r || vr <= l) {
        return INF;
    }
    if (vl >= l && vr <= r) {
        return tree[v] + tree_add[v];
    }
    int mid = (vl + vr) / 2;
    return min(get(v * 2 + 1, vl, mid, l, r), get(v * 2 + 2, mid, vr, l, r)) + tree_add[v];
}

void upd(int v, int vl, int vr, int l, int r, int x) {
    if (vl >= r || vr <= l) {
        return;
    }
    if (vl >= l && vr <= r) {
        tree_add[v] += x;
    } else {
        int mid = (vl + vr) / 2;
        upd(v * 2 + 1, vl, mid, l, r, x);
        upd(v * 2 + 2, mid, vr, l, r, x);
        tree[v] = min(tree[v * 2 + 1] + tree_add[v * 2 + 1], tree[v * 2 + 2] + tree_add[v * 2 + 2]);
    }
}

inline int get(int l, int r) {
    return get(0, 1, n + 1, l, r);
}
inline void upd(int l, int r, int x) {
    upd(0, 1, n + 1, l, r, x);
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", songs + i);
        sorted.emplace_back(songs[i], i);
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i += MAGIC1) {
        places.push_back(vector<int>());
        first.push_back(vector<int>());
        mn.push_back(vector<int>());

        for (int j = 1; j <= n; j += MAGIC2) {
            places.back().push_back(j);
        }
        places.back().push_back(n + 1);
        for (int j = i; j < i + MAGIC1 && j < n; j++) {
            places.back().push_back(max(1, sorted[j].sc - m + 1));
            places.back().push_back(sorted[j].sc + 1);
        }
        sort(places.back().begin(), places.back().end());
        places.back().resize(distance(places.back().begin(), unique(places.back().begin(), places.back().end())));
        for (int j = 0; j < (int) places.back().size() - 1; j++) {
            first.back().push_back(get(places.back()[j], places.back()[j] + 1));
            mn.back().push_back(get(places.back()[j], places.back()[j + 1]));
        }

        for (int j = i; j < i + MAGIC1 && j < n; j++) {
            upd(max(1, sorted[j].sc - m + 1), sorted[j].sc + 1, 1);
            add[j].fs = (int) (lower_bound(places.back().begin(), places.back().end(), max(1, sorted[j].sc - m + 1)) - places.back().begin());
            add[j].sc = (int) (lower_bound(places.back().begin(), places.back().end(), sorted[j].sc + 1) - places.back().begin());
        }
    }

    scanf("%d", &s);
    int pre = 0;
    for (int i = 0; i < s; i++) {
        int l, r, q;
        scanf("%d%d%d", &l, &r, &q);
        r++;
        q ^= pre;
        int t = (int) (lower_bound(sorted.begin(), sorted.end(), make_pair(q, 0)) - sorted.begin());
        int cur = t / MAGIC1;
        if (cur == (int) places.size()) {
            cur--;
        }
        vector<int> dp(places[cur].size());
//        for (auto i : places[cur]) {
//            cout << i << ' ';
//        }
//        cout << endl;
//        for (auto i : mn[cur]) {
//            cout << i << ' ';
//        }
//        cout << endl;
//        for (auto i : first[cur]) {
//            cout << i << ' ';
//        }
//        cout << endl;
        for (int j = cur * MAGIC1; j < t; j++) {
            dp[add[j].fs]++;
            dp[add[j].sc]--;
        }
        for (int j = 1; j < (int) dp.size(); j++) {
            dp[j] += dp[j - 1];
        }
        int ans = INF;
        int ll = INF, rr = -1;
        for (int j = 0; j < (int) places[cur].size() - 1; j++) {
            if (places[cur][j] >= l && places[cur][j + 1] <= r) {
                ans = min(ans, mn[cur][j] + dp[j]);
                ll = min(ll, j);
                rr = j + 1;
            }
        }
//        cout << ll << ' ' << rr << endl;
        if (ll != INF) {
            for (int j = places[cur][ll] - 1, z = first[cur][ll] + dp[ll]; j >= l; j--) {
                if (songs[j] < q) {
                    z++;
                }
                if (j + m <= n && songs[j + m] < q) {
                    z--;
                }
                ans = min(ans, z);
            }
            if (places[cur][rr] < n + 1) {
                for (int j = places[cur][rr], z = first[cur][rr] + dp[rr]; j < r; j++) {
                    ans = min(ans, z);
                    if (songs[j] < q) {
                        z--;
                    }
                    if (j + m <= n && songs[j + m] < q) {
                        z++;
                    }
                }
            }
        } else {
            ll = 0;
            while (places[cur][ll + 1] <= l) {
                ll++;
            }
            int z = first[cur][ll] + dp[ll];
            for (int j = places[cur][ll]; j < r; j++) {
                if (j >= l) {
                    ans = min(ans, z);
                }
                if (songs[j] < q) {
                    z--;
                }
                if (j + m <= n && songs[j + m] < q) {
                    z++;
                }
            }
        }
        printf("%d\n", ans);
        pre = ans;
    }
    return 0;
}