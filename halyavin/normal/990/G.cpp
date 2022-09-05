#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

int64_t full(int x) {
    return int64_t(x) * int64_t(x + 1) / 2;
}

struct Solution {
    int n;
    std::vector<int> as;
    std::vector<std::vector<int>> graph;
    std::vector<int64_t> answers;

    const int calc = 200000;
    std::vector<std::vector<int>> divisors;
    std::vector<int> numDivisors;

    std::vector<std::vector<int>> hist;
    std::vector<int> comp;
    std::vector<int> visited;
    int component;

    void init() {
        numDivisors.assign(calc + 1, 0);
        divisors.assign(calc + 1, std::vector<int>());
        for (int i = 1; i <= calc; i++) {
            for (int j = i; j <= calc; j += i) {
                numDivisors[j]++;
            }
        }
        for (int i = 1; i <= calc; i++) {
            divisors[i].reserve(numDivisors[i]);
        }
        for (int i = 1; i <= calc; i++) {
            for (int j = i; j <= calc; j += i) {
                divisors[j].push_back(i);
            }
        }
    }

    int rec1(int x, int prev) {
        int res = 1;
        visited[x] = component;
        for (int nx : graph[x]) {
            if (nx != prev && comp[nx] == component) {
                res += rec1(nx, x);
            }
        }
        return res;
    }

    void calculate(int d) {
        component++;
        for (int v : hist[d]) {
            comp[v] = component;
        }
        for (int v : hist[d]) {
            if (visited[v] != component) {
                int size = rec1(v, -1);
                answers[d] += full(size);
            }
        }
    }

    void run(std::istream &in, std::ostream &out) {
        init();
        in >> n;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        graph.assign(n, std::vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            in >> x >> y;
            x--;y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        answers.assign(calc + 1, 0);
        hist.assign(calc + 1, std::vector<int>());
        comp.assign(n, 0);
        visited.assign(n, 0);
        component = 0;
        for (int i = 0; i < n; i++) {
            for (int d : divisors[as[i]]) {
                hist[d].push_back(i);
            }
        }
        for (int d = 1; d <= calc; d++) {
            if (hist[d].empty()) {
                continue;
            }
            calculate(d);
        }

        for (size_t i = answers.size(); i-- > 0;) {
            for (int d : divisors[i]) {
                if (d < i) {
                    answers[d] -= answers[i];
                }
            }
        }
        for (size_t i = 1; i < answers.size(); i++) {
            if (answers[i] != 0) {
                out << i << " " << answers[i] << "\n";
            }
        }
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}