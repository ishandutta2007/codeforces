#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Result {
    std::vector<int> stats;
    int maxValue = 1;
    int maxIndex = 0;
};

struct Solution {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<int> treeSize;
    std::vector<int> largestChild;
    std::vector<int> answers;

    void preCalcDfs(int v, int prev) {
        int size = 1;
        int maxChildSize = 0;
        int maxChildIdx = -1;
        for (int nv : graph[v]) {
            if (nv == prev) continue;
            preCalcDfs(nv, v);
            size = std::max(size, 1 + treeSize[nv]);
            if (treeSize[nv] > maxChildSize) {
                maxChildSize = treeSize[nv];
                maxChildIdx = nv;
            }
        }
        treeSize[v] = size;
        largestChild[v] = maxChildIdx;
    }

    Result dfs(int v, int prev) {
        Result result;
        if (treeSize[v] == 1) {
            result.stats.push_back(1);
            answers[v] = result.stats.size() - result.maxIndex - 1;
            return result;
        }
        int maxChildIdx = largestChild[v];
        result = dfs(maxChildIdx, v);
        result.stats.push_back(1);
        if (result.maxValue == 1) {
            result.maxIndex = result.stats.size() - 1;
        }
        for (int nv : graph[v]) {
            if (nv == prev || nv == maxChildIdx) continue;
            Result childResult = dfs(nv, v);
            size_t j = result.stats.size() - 2;
            for (size_t i = childResult.stats.size(); i-- > 0; j--) {
                result.stats[j] += childResult.stats[i];
                if (result.stats[j] > result.maxValue ||
                    (result.stats[j] == result.maxValue && j > result.maxIndex)) {
                    result.maxValue = result.stats[j];
                    result.maxIndex = j;
                }
            }
        }
        answers[v] = result.stats.size() - result.maxIndex - 1;
        return result;
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        graph.assign(n, std::vector<int>());
        treeSize.assign(n, 0);
        largestChild.assign(n, 0);
        answers.assign(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int from, to;
            in >> from >> to;
            from--;
            to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        preCalcDfs(0, -1);
        dfs(0, -1);
        for (int i = 0; i < n; i++) {
            out << answers[i] << "\n";
        }
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}