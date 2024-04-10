#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <numeric>

template<class T>
struct LazyBinTree {
    size_t size;
    std::vector<T> t;
    std::vector<T> mod;

    LazyBinTree(size_t N) :
            size(N),
            t(2 * N),
            mod(N) {}

    LazyBinTree(const std::vector<T> &other) :
            size(other.size()),
            t(2 * other.size()),
            mod(other.size()) {
        std::copy(other.begin(), other.end(), t.begin() + size);
        for (size_t i = size; i-- > 1;) {
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }

    T query(size_t l, size_t r) {
        if (l == r) return 0;
        T sum = T();
        l += size;
        r += size;
        size_t level = 1;
        size_t leftMult = 0;
        size_t rightMult = 0;
        while (l < r) {
            if (leftMult != 0) {
                sum += mod[l - 1] * leftMult;
            }
            if (l & 1) {
                sum += t[l];
                leftMult += level;
                l++;
            }
            if (rightMult != 0) {
                sum += mod[r] * rightMult;
            }
            if (r & 1) {
                r--;
                sum += t[r];
                rightMult += level;
            }
            l /= 2;
            r /= 2;
            level *= 2;
        }
        l--;
        while (r > 0) {
            if (leftMult > 0) sum += mod[l] * leftMult;
            if (rightMult > 0) sum += mod[r] * rightMult;
            l /= 2;
            r /= 2;
        }
        return sum;
    }

    void modify(size_t l, size_t r, T value) {
        if (l == r) return;
        l += size;
        r += size;
        size_t level = 1;
        T leftAdd = 0;
        T rightAdd = 0;
        while (l < r) {
            if (leftAdd != 0) {
                t[l - 1] += leftAdd;
            }
            if (l & 1) {
                if (l < size) {
                    mod[l] += value;
                }
                t[l] += level * value;
                leftAdd += level * value;
                l++;
            }
            if (rightAdd != 0) {
                t[r] += rightAdd;
            }
            if (r & 1) {
                r--;
                if (r < size) {
                    mod[r] += value;
                }
                t[r] += level * value;
                rightAdd += level * value;
            }
            l /= 2;
            r /= 2;
            level *= 2;
        }
        l--;
        while (r > 0) {
            t[l] += leftAdd;
            t[r] += rightAdd;
            l /= 2;
            r /= 2;
        }
    }

    T query(size_t p) {
        p += size;
        T res = t[p];
        while (p > 1) {
            p = p / 2;
            res += mod[p];
        }
        return res;
    }

    void modify(size_t p, T value) {
        p += size;
        while (p > 0) {
            t[p] += value;
            p = p / 2;
        }
    }
};

const int mod = 1000000007;

int add32(int x, int y) {
    int res = x + y;
    if (res >= mod) res -= mod;
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += mod;
    return res;
}

int mul32(int x, int y) {
    return int((int64_t(x) * y) % mod);
}

struct Solution {
    std::unique_ptr<LazyBinTree<int64_t>> tree;
    std::vector<int> as;
    std::vector<int> order;
    int n;

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        order.resize(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [this](int left, int right) { return as[left] < as[right]; });
        tree.reset(new LazyBinTree<int64_t>(n + 1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int pos = order[i];
            tree->modify(pos + 1, n + 1, 1);
            int A = pos + 1;
            int B = n - pos;
            int left = sub32(mul32(A, tree->query(pos + 1) % mod), tree->query(0, pos + 1) % mod);
            //std::cerr << "left " << i << " " << left << "\n";
            int cf = mul32(left, B);
            int right = sub32(tree->query(pos + 1, n + 1) % mod, mul32(B, tree->query(pos + 1) % mod));
            //std::cerr << "right " << i << " " << right << "\n";
            cf = add32(cf, mul32(right, A));
            //std::cerr << i << " " << cf << "\n";
            ans = add32(ans, mul32(cf, as[pos]));
        }
        out << ans << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}