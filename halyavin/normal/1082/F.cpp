#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

struct Node {
    int total;
    std::array<int, 10> next;
    Node(): total(0), next() {
    }
};
struct Solution {
    int n, k;
    std::vector<std::string> ss;
    std::vector<int> ms;
    std::vector<Node> tree;
    std::vector<std::vector<std::vector<int>>> dyn;
    void buildTree() {
        for (int i = 0; i < n; i++) {
            int cur = 0;
            std::string s = ss[i];
            int m = ms[i];
            tree[cur].total += m;
            for (char c : s) {
                int d = c - '0';
                if (tree[cur].next[d] == 0) {
                    tree[cur].next[d] = tree.size();
                    tree.emplace_back();
                }
                cur = tree[cur].next[d];
                tree[cur].total += m;
            }
        }
    }
    void solveDyn(int v, int maxGl) {
        dyn[v].assign(maxGl, std::vector<int>(k + 1));
        for (int i = 0; i < 10; i++) {
            if (tree[v].next[i] != 0) {
                solveDyn(tree[v].next[i], maxGl + 1);
            }
        }
        std::vector<int> other(k + 1);
        for (int gl = 0; gl < maxGl; gl++) {
            for (int i = 0; i < 10; i++) {
                if (tree[v].next[i] == 0) {
                    continue;
                }
                other = dyn[v][gl];
                std::vector<int>& cur = dyn[v][gl];
                std::vector<int>& sub = dyn[tree[v].next[i]][gl + 1];
                for (int ii = 0; ii <= k; ii++) {
                    for (int jj = 0; jj <= k - ii; jj++) {
                        other[ii + jj] = std::max(other[ii + jj], cur[ii] + sub[jj]);
                    }
                }
                std::swap(dyn[v][gl], other);
            }
            int opt = gl * tree[v].total;
            std::vector<int> res(k + 1);
            for (int i = 0; i < 10; i++) {
                if (tree[v].next[i] == 0) {
                    continue;
                }
                other = res;
                std::vector<int>& cur = res;
                std::vector<int>& sub = dyn[tree[v].next[i]][1];
                for (int ii = 0; ii < k; ii++) {
                    for (int jj = 0; jj < k - ii; jj++) {
                        other[ii + jj] = std::max(other[ii + jj], cur[ii] + sub[jj]);
                    }
                }
                std::swap(other, res);
            }
            for (int ii = 0; ii < k; ii++) {
                dyn[v][gl][ii + 1] = std::max(dyn[v][gl][ii + 1], res[ii] + opt);
            }
        }
    }
    void run(std::istream& in, std::ostream& out) {
        in >> n >> k;
        ss.resize(n);
        ms.resize(n);
        for (int i = 0; i < n; i++) {
            in >> ss[i];
            in >> ms[i];
        }
        tree.clear();
        tree.emplace_back();
        buildTree();
        dyn.assign(tree.size(), std::vector<std::vector<int>>());
        solveDyn(0, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ss[i].length() * ms[i];
        }
        int maxValue = 0;
        for (int i = 0; i <= k; i++) {
            maxValue = std::max(maxValue, dyn[0][0][i]);
        }
        ans -= maxValue;
        out << ans << "\n";

    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}