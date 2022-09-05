#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <memory>

struct BinTree1 {
    using T = std::pair<int, int>;
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

    void modify(size_t p, int v) {
        T value{v, v};
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
        return {std::min(left.first, right.first), std::max(left.second, right.second)};
    }

    T init() {
        return T{1000000000, -1000000000};
    }
};
struct Solution {
    int n, k;
    std::vector<std::unique_ptr<BinTree1>> trees;
    void run(std::istream &in, std::ostream &out) {
        in >> n >> k;
        trees.clear();
        trees.resize(1 << (k - 1));
        std::vector<std::vector<std::pair<int, int>>> init(1 << (k - 1), std::vector<std::pair<int, int>>(n));
        for (int i = 0; i < n; i++) {
            std::vector<int> as(k);
            for (int j = 0; j < k; j++) {
                in >> as[j];
            }
            for (int mask = 0; mask < (1 << (k - 1)); mask++) {
                int res =  0;
                for (int j = 0; j < k; j++) {
                    if ((mask & (1 << j)) != 0) {
                        res -= as[j];
                    } else {
                        res += as[j];
                    }
                }
                init[mask][i].first = res;
                init[mask][i].second = res;
            }
        }
        for (size_t i = 0; i < trees.size(); i++) {
            trees[i].reset(new BinTree1(init[i]));
        }
        int q;
        in >> q;
        for (int query = 0; query < q; query++) {
            int t;
            in >> t;
            if (t == 1) {
                int idx;
                in >> idx;
                idx--;
                std::vector<int> as(k);
                for (int j = 0; j < k; j++) {
                    in >> as[j];
                }
                for (int mask = 0; mask < (1 << (k - 1)); mask++) {
                    int res =  0;
                    for (int j = 0; j < k; j++) {
                        if ((mask & (1 << j)) != 0) {
                            res -= as[j];
                        } else {
                            res += as[j];
                        }
                    }
                    trees[mask]->modify(idx, res);
                }
            } else {
                int l, r;
                in >> l >> r;
                l--;
                int res = 0;
                for (int mask = 0; mask < (1 << (k - 1)); mask++) {
                    auto minMax = trees[mask]->query(l, r);
                    res = std::max(res, minMax.second - minMax.first);
                }
                out << res << "\n";
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