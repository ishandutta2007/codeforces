#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

template<class T>
struct BinTree1 {
    size_t size;
    std::vector<T> t;

    BinTree1(size_t N) :
            size(N),
            t(2 * N) {}

    BinTree1(const std::vector<T> &other) :
            size(other.size()),
            t(2 * other.size()) {
        std::copy(other.begin(), other.end(), t.begin() + size);
        for (size_t i = size; i-- > 1;) {
            t[i] = combine(t[2 * i], t[2 * i + 1]);
        }
    }

    T get(size_t p) {
        return t[p + size];
    }

    void modify(size_t p, T value) {
        p += size;
        t[p] = value;
        while (p > 1) {
            p = p / 2;
            t[p] = combine(t[2 * p], t[2 * p + 1]);
        }
    }

    T query(size_t l, size_t r) {
        l += size;
        r += size;
        T left = init();
        T right = init();
        while (l < r) {
            if (l & 1) {
                left = combine(left, t[l]);
                l++;
            }
            if (r & 1) {
                r--;
                right = combine(t[r], right);
            }
            l = l / 2;
            r = r / 2;
        }
        return combine(left, right);
    }

private:
    T combine(T left, T right) {
        return left + right;
    }

    T init() {
        return T();
    }
};

struct Solution {
    std::vector<std::array<int, 3>> vert;
    std::vector<std::array<int, 3>> hor;
    int n;

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        vert.clear();
        hor.clear();
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            in >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                vert.push_back(std::array<int, 3>{x1, std::min(y1, y2), std::max(y1, y2)});
            } else {
                hor.push_back(std::array<int, 3>{y1, std::min(x1, x2), std::max(x1, x2)});
            }
        }
        std::sort(vert.begin(), vert.end());
        std::vector<int> stat(10001);
        int64_t answer = 0;
        for (size_t i = 0; i < vert.size(); i++) {
            const auto &vInterval = vert[i];

            std::vector<std::pair<int, int>> events;
            std::fill(stat.begin(), stat.end(), 0);
            for (const auto &interval : hor) {
                if (interval[0] < vInterval[1] || interval[0] > vInterval[2]) {
                    continue;
                }
                if (vInterval[0] < interval[1] || vInterval[0] > interval[2]) {
                    continue;
                }
                events.emplace_back(interval[2], interval[0]);
                stat[interval[0] + 5000]++;
            }
            std::sort(events.begin(), events.end());
            size_t pos = 0;
            BinTree1<int> tree(stat);
            for (size_t j = i + 1; j < vert.size(); j++) {
                int x = vert[j][0];
                while (pos < events.size() && events[pos].first < x) {
                    tree.modify(events[pos].second + 5000, 0);
                    pos++;
                }
                int intersect = tree.query(vert[j][1] + 5000, vert[j][2] + 5000 + 1);
                answer += intersect * (intersect - 1) / 2;
            }
        }
        out << answer << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}