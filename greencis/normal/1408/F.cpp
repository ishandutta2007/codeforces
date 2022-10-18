#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

/*set<vector<int>> st;
int u = 16;
map<pii, int> mp;

int get(int x, int y) {
    if (!mp.count(make_pair(x, y))) {
        mp[{x, y}] = u++;
    }
    return mp[{x, y}];
}

vector<int> normalize(vector<int> v) {
    sort(all(v));
    int cur = 1;
    for (int i = 0; i < (int)v.size(); ++i) {
        bool next_change = (i + 1 < (int)v.size() && v[i + 1] != v[i]);
        v[i] = cur;
        cur += next_change;
    }
    return v;
}

void brute(vector<int> v) {
    if (st.count(normalize(v))) return;
    st.insert(normalize(v));
    for (int x : v) cout << x << ' ';
    if (normalize(v).back() <= 2) { cout << "good!"; exit(1); }
    cout << endl;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            auto vv = v;
            int q = get(vv[i], vv[j]);
            vv[i] = q;
            vv[j] = q;
            sort(all(vv));
            brute(vv);
        }
    }
}*/

vector<pii> ops;

void process(const vector<int>& v) {
    int n = v.size();
    for (int len = 1; len * 2 <= n; len *= 2) {
        for (int i = 0; i < n; i += len * 2) {
            for (int j = 0; j < len; ++j) {
                ops.emplace_back(v[i + j], v[i + j + len]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    //brute(v);

    int n;
    cin >> n;
    int deg2 = 1;
    while (deg2 <= n) deg2 *= 2;
    deg2 /= 2;
    vector<int> v(deg2);
    iota(all(v), 1);
    process(v);

    vector<int> others;
    for (int i = deg2 + 1; i <= n; ++i)
        others.push_back(i);
    vector<int> buf;
    for (int h = 0; v.size() + buf.size() < n; ++h) {
        if (n & (1 << h)) {
            while (buf.size() < (1 << h)) {
                buf.push_back(v.back());
                v.pop_back();
            }
            for (int i = 0; i < (1 << h); ++i) {
                buf.push_back(others.back());
                others.pop_back();
            }
            process(buf);
        }
    }

    if (ops.size() > 5e5) exit(1);
    cout << ops.size() << '\n';
    for (const auto& qqq : ops) {
        cout << qqq.first << ' ' << qqq.second << '\n';
    }
}