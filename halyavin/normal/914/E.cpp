#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

struct Solution {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<uint8_t> excludeMask;
    std::vector<int64_t> result;
    std::vector<int> treeSize;
    std::vector<int> masks;
    std::vector<int> counts;
    std::vector<int> labels;

    int dfsSize(int v, int prev) {
        int res = 1;
        for (int nv : graph[v]) {
            if (nv != prev && excludeMask[nv] == 0) {
                res += dfsSize(nv, v);
            }
        }
        treeSize[v] = res;
        return res;
    }

    int center(int root) {
        int all = dfsSize(root, -1);
        bool good;
        int prev = -1;
        do {
            good = false;
            for (int nv : graph[root]) {
                if (nv != prev && excludeMask[nv] == 0 && treeSize[nv] > all / 2) {
                    good = true;
                    prev = root;
                    root = nv;
                    break;
                }
            }
        } while (good);
        return root;
    }

    void addMasks(int v, int prev, int mask) {
        mask ^= labels[v];
        //masks[v] = mask;
        counts[mask]++;
        for (int nv : graph[v]) {
            if (nv != prev && excludeMask[nv] == 0) {
                addMasks(nv, v, mask);
            }
        }
    }

    void subMasks(int v, int prev, int mask) {
        mask ^= labels[v];
        //masks[v] = mask;
        counts[mask]--;
        for (int nv : graph[v]) {
            if (nv != prev && excludeMask[nv] == 0) {
                subMasks(nv, v, mask);
            }
        }
    }

    int64_t addResult(int v, int prev, int mask, std::array<int, 21>& check) {
        mask ^= labels[v];
        int64_t res = 0;
        for (int c : check) {
            res += counts[c ^ mask];
        }
        for (int nv : graph[v]) {
            if (nv != prev && excludeMask[nv] == 0) {
                res += addResult(nv, v, mask, check);
            }
        }
        result[v] += res;
        return res;
    }

    void calc(int root) {
        root = center(root);
        for (int nv : graph[root]) {
            if (excludeMask[nv] == 0) {
                addMasks(nv, root, 0);
            }
        }
        std::array<int, 21> checks;
        int lroot = labels[root];
        checks[0] = lroot;
        for (int i = 0; i < 20; i++) {
            checks[i + 1] = lroot ^ (1 << i);
        }
        int64_t rootSimple = 0;
        for (int c : checks) {
            rootSimple += counts[c];
        }
        int64_t rootResult = rootSimple;
        counts[0]++;
        for (int nv : graph[root]) {
            if (excludeMask[nv] == 0) {
                subMasks(nv, root, 0);
                rootResult += addResult(nv, root, 0, checks);
                addMasks(nv, root, 0);
            }
        }
        counts[0]--;
        rootResult /= 2;
        rootResult++;
        result[root] += rootResult;
        for (int nv : graph[root]) {
            if (excludeMask[nv] == 0) {
                subMasks(nv, root, 0);
            }
        }
        excludeMask[root] = 1;
        for (int nv : graph[root]) {
            if (excludeMask[nv] == 0) {
                calc(nv);
            }
        }
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n;
        graph.assign(n, std::vector<int>());
        result.assign(n, 0);
        treeSize.resize(n);
        masks.resize(n);
        counts.assign(1 << 20, 0);
        labels.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int from, to;
            in >> from >> to;
            from--;
            to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for (size_t i = 0; i < n; i++) {
            std::sort(graph[i].begin(), graph[i].end());
        }
        std::string s;
        in >> s;
        for (int i = 0; i < n; i++) {
            labels[i] = 1 << (s[i] - 'a');
        }
        excludeMask.assign(n, 0);
        calc(0);
        for (size_t i = 0; i < n; i++) {
            out << result[i] << " ";
        }
        out << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}