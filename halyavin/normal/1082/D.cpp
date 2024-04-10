#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <stack>

struct Solution {
    int n;
    std::vector<std::pair<int, int>> edges;
    std::stack<int> ones;
    std::vector<int> degs;
    std::vector<int> mults;
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        degs.resize(n);
        for (int i = 0; i < n; i++) {
            in >> degs[i];
        }
        ones = std::stack<int>();
        mults.clear();
        for (int i = 0; i < n; i++) {
            if (degs[i] == 1) {
                ones.push(i);
            } else {
                mults.push_back(i);
            }
        }
        std::sort(mults.begin(), mults.end(), [this](int i, int j) { return degs[i] > degs[j]; });
        if (mults.empty()) {
            out << "NO\n";
            return;
        }
        if (std::accumulate(degs.begin(), degs.end(), 0) < 2 * (n - 1)) {
            out << "NO\n";
            return;
        }
        if (ones.empty()) {
            out << "YES " << (n - 1) << "\n";
            out << (n - 1) << "\n";
            for (int i = 0; i < n - 1; i++) {
                out << (i + 1) << " " << (i + 2) << "\n";
            }
            return;
        }
        edges.clear();
        int v = ones.top();
        ones.pop();
        int d = 0;
        int mIndex = 0;
        while (ones.size() > 1 && mIndex < mults.size() && degs[mults[mIndex]] > 2) {
            int next = mults[mIndex];
            mIndex++;
            for (int i = 2; i < degs[next] && ones.size() > 1; i++) {
                edges.emplace_back(next, ones.top());
                ones.pop();
            }
            edges.emplace_back(next, v);
            d++;
            v = next;
        }
        if (ones.size() > 1) {
            out << "NO\n";
            return;
        }
        if (mIndex == mults.size() && ones.empty()) {
            d++;
        } else {
            for (; mIndex < mults.size(); mIndex++) {
                edges.emplace_back(v, mults[mIndex]);
                v = mults[mIndex];
                d++;
            }
            if (!ones.empty()) {
                edges.emplace_back(v, ones.top());
                v = ones.top();
                d++;
            }
        }
        out << "YES " << d << "\n";
        out << edges.size() << "\n";
        for (const auto& edge : edges) {
            out << (edge.first + 1) << " " << (edge.second + 1) << "\n";
        }
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}