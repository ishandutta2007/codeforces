#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <fstream>
#include <array>
#include <memory>

struct BinTree1 {
    using T = std::pair<int64_t, int>;
    size_t size;
    std::vector<T> t;

    BinTree1(const std::vector<int64_t>& other) :
        size(other.size()),
        t(2 * other.size()) {
        for (size_t i = 0; i < size; i++) {
            t[i + size].first = other[i];
            t[i + size].second = 1;
        }
        for (size_t i = size; i-- > 1;) {
            t[i] = combine(t[2 * i], t[2 * i + 1]);
        }
    }

    T get(size_t p) {
        return t[p + size];
    }

    void modify(size_t p) {
        p += size;
        t[p].first = 0;
        t[p].second = 0;
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
        return {left.first + right.first, left.second + right.second};
    }

    T init() {
        return T();
    }
};

struct Solution {
    int n;
    int64_t T;
    std::vector<int64_t> as;
    std::vector<std::pair<int64_t, int>> order;
    int lastOrder;
    int64_t ans;
    std::unique_ptr<BinTree1> tree;

    void updateLastOrder() {
        while (lastOrder >= 0 && order[lastOrder].first > T) {
            tree->modify(order[lastOrder].second);
            lastOrder--;
        }
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n >> T;
        as.resize(n);
        order.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
            order[i].first = as[i];
            order[i].second = i;
        }
        std::sort(order.begin(), order.end());
        lastOrder = n - 1;
        ans = 0;
        tree.reset(new BinTree1(as));
        while (lastOrder >= 0 && T >= 0) {
            updateLastOrder();
            if (lastOrder < 0) {
                break;
            }
            auto all = tree->query(0, n);
            if (all.first <= T) {
                ans += (T / all.first) * all.second;
                T = T % all.first;
                continue;
            }
            int pos = 0;
            while (pos < n) {
                int right = n;
                std::pair<int64_t, int> res;
                while (right - pos > 1 && (res = tree->query(pos, right)).first > T) {
                    right = (right + pos) / 2;
                }
                if (right - pos == 1) {
                    if (as[pos] <= T) {
                        T -= as[pos];
                        ans++;
                    }
                    pos++;
                } else {
                    T -= res.first;
                    ans += res.second;
                    pos = right;
                }
                updateLastOrder();
            }
        }
        out << ans << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::ifstream fin("input.txt");
    // std::ofstream fout("output.txt");
    // run(fin, fout);
    Solution().run(std::cin, std::cout);
    return 0;
}