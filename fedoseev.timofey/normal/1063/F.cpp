#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;

struct SegmentTree {
    int n;
    vector <int> t;

    void build(const vector <int> &a) {
        for (int i = 0; i < n; ++i) {
            t[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }

    void modify(int x, int val) {
        for (t[x += n] = val; x > 1; x >>= 1) {
            t[x >> 1] = max(t[x], t[x ^ 1]);
        }
    }

    int get(int l, int r) {
        ++r;
        int res = -Inf;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }

    SegmentTree(const vector <int> &a) {
        n = a.size();
        t.resize(2 * n, -Inf);
        build(a);
    }
};

struct SparseTable {
    int n, k;
    vector <vector <int>> ST;
    vector <int> lg;

    void init(vector <int> a) {
        n = a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
        k = 0;
        while ((1 << k) <= n) ++k;
        ++k;
        
        ST.resize(k, vector <int> (n, Inf));
        for (int i = 0; i < n; ++i) {
            ST[0][i] = a[i];
        }
        for (int j = 1; j < k; ++j) {
            for (int i = 0; i < n; ++i) {
                ST[j][i] = ST[j - 1][i];
                if (i + (1 << (j - 1)) < n) {
                    ST[j][i] = min(ST[j][i], ST[j - 1][i + (1 << (j - 1))]);
                }
            }
        }
    }
    int get(int l, int r) {
        int x = lg[r - l + 1];
        return min(ST[x][l], ST[x][r - (1 << x) + 1]);
    }
};


struct SuffixArray {
    string s;
    vector <int> suf;
    vector <int> lcp;
    vector <int> id;
    int n;
    SparseTable rmq;

    void buildSuf(string s) {
        s.push_back('$');
        int n = s.size();
        vector <int> p(n), c(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        sort(p.begin(), p.end(), [&] (int x, int y) {
            return s[x] < s[y] || (s[x] == s[y] && x < y);
        });
        for (int i = 1; i < n; ++i) c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
        vector <int> ps(n), np(n), nc(n);
        for (int pw = 0; (1 << pw) < n; ++pw) {
            fill(ps.begin(), ps.end(), 0);
            for (int i = 0; i < n; ++i) {
                p[i] = p[i] - (1 << pw);
                p[i] = (p[i] < 0 ? p[i] + n : p[i]);
                ++ps[c[p[i]]];
            }
            for (int i = 1; i < n; ++i) ps[i] += ps[i - 1];
            for (int i = n - 1; i >= 0; --i) np[--ps[c[p[i]]]] = p[i];
            nc[0] = 0;
            for (int i = 1; i < n; ++i) {
                int w = np[i] + (1 << pw);
                w = (w >= n ? w - n : w);
                int v = np[i - 1] + (1 << pw);
                v = (v >= n ? v - n : v);
                nc[np[i]] = nc[np[i - 1]] + (c[np[i]] != c[np[i - 1]] || c[w] != c[v]);
            }
            c = nc;
            p = np;
        }
        for (int i = 1; i < n; ++i) suf.push_back(p[i]);
        for (int i = 0; i < (int)suf.size(); ++i) {
            id[suf[i]] = i;
        }
    }

    void buildLcp(string s) {
        lcp.resize(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur) --cur;
            if (id[i] == n - 1) {
                cur = 0;
                continue;
            }
            int j = suf[id[i] + 1];
            while (i + cur < n && j + cur < n && s[i + cur] == s[j + cur]) ++cur;
            lcp[id[i]] = cur;
        }
    }


    SuffixArray(string t) {
        s = t;
        n = s.size();
        id.resize(n);
        buildSuf(s);
        buildLcp(s);
        rmq.init(lcp);
    }

    int getLcp(int l, int r) {
        if (l == r) {
            return n - l;
        }
        return rmq.get(l, r - 1);
    }

};

int n;

bool check(int i, int k, SuffixArray &suf, SegmentTree &rmq) {
    int low = -1, high = i;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (suf.getLcp(mid, i) >= k - 1) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    int l = high;
    low = i;
    high = n;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (suf.getLcp(i, mid) >= k - 1) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    int r = low;
    return rmq.get(l, r) >= k - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    cin >> n;
    string s;
    cin >> s;
    SuffixArray suf(s);
    SegmentTree best(vector <int> (n, -1));
    vector <int> dp(n);
    int last = 0;
    int j = n;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = last + 1;
        while (dp[i] > 1) {
            int fir = suf.id[i];
            int sec = suf.id[i + 1];
            if (check(fir, dp[i], suf, best) || check(sec, dp[i], suf, best)) break;
            --dp[i];
            --j;
            best.modify(suf.id[j], dp[j]);
        }
        last = dp[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans << '\n';
}