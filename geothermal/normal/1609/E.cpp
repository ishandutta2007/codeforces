// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <chrono>

#define fi first
#define se second
#define m_p make_pair
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;

const int inf = int(1e9);

int masksMerge[40][40];
vector <string> bits = {"a", "b", "c", "ab", "bc"};

bool contains(const string& s, const string& sub) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (pos < sub.size() && s[i] == sub[pos]) pos++;
    }
    return pos >= sub.size();
}

int totalMask(const vector<string>& firstMask, const vector<string>& secondMask) {
    int msk = 0;
    for (const auto& f : firstMask) {
        for (const auto& s : secondMask) {
            string merged = f + s;
            if (contains(merged, "abc")) {
                return -1;
            }

            for (int bit = 0; bit < 5; ++bit) {
                if (contains(merged, bits[bit])) {
                    msk |= (1 << bit);
                }
            }
        }
    }
    return msk;
}

void precalc() {
    for (int msk1 = 0; msk1 < 32; ++msk1) {
        for (int msk2 = 0; msk2 < 32; ++msk2) {
            vector<string> firstMask, secondMask;
            for (int i = 0; i < 5; ++i) {
                if (msk1 & (1 << i)) firstMask.push_back(bits[i]);
                if (msk2 & (1 << i)) secondMask.push_back(bits[i]);
            }
            firstMask.push_back("");
            secondMask.push_back("");
            int msk = totalMask(firstMask, secondMask);
            masksMerge[msk1][msk2] = msk;

        }
    }
}

struct Node {
    vector <int> dp;

    Node() {
        dp.resize(40, inf);
    }
};

struct Tree {
private:
    int n;
    vector<Node> nodes;

    void merge(int v) {
        for (int i = 0; i < 32; ++i) nodes[v].dp[i] = inf;

        for (int msk1 = 0; msk1 < 32; ++msk1) {

            for (int msk2 = 0; msk2 < 32; ++msk2) {
                int newMask = masksMerge[msk1][msk2];
                if (newMask != -1) {
                    nodes[v].dp[newMask] = min(nodes[v].dp[newMask], nodes[v * 2].dp[msk1] + nodes[v * 2 + 1].dp[msk2]);
                }
            }
        }
    }

    void build(int v, int tl, int tr, const string& s) {
        if (tl == tr) {
            int mskPos = int(s[tl - 1] - 'a');
            nodes[v].dp[(1 << mskPos)] = 0;
            nodes[v].dp[0] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, s);
        build(v * 2 + 1, tm + 1, tr, s);
        merge(v);
    }

    void modify(int v, int tl, int tr, int pos, char val) {
        if (tl == tr) {
            for (int i = 0; i < 33; ++i) nodes[v].dp[i] = inf;
            int mskPos = int(val - 'a');
            nodes[v].dp[(1 << mskPos)] = 0;
            nodes[v].dp[0] = 1;
            return;
        }

        int tm = (tl + tr) / 2;
        if (pos <= tm) modify(v * 2, tl, tm, pos, val);
        else modify(v * 2 + 1, tm + 1, tr, pos, val);
        merge(v);
    }

public:
    Tree(const string& s) {
        n = int(s.size());
        nodes.resize(4 * n);
        build(1, 1, n, s);
    }

    void update(int pos, char x) {
        modify(1, 1, n, pos, x);
    }

    int get() {
        int ans = inf;
        for (int i = 0; i < 32; ++i) {
            ans = min(ans, nodes[1].dp[i]);
        }
        return ans;
    }

};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    Tree tree(s);

    while (q--) {
        int pos;
        char x;
        cin >> pos >> x;
        tree.update(pos, x);
        cout << tree.get() << '\n';
    }
}

int main()
{
    fast_io;
    precalc();
    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}