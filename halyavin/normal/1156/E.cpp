#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <memory>

struct BinTree1 {
    using T = int;
    size_t size;
    std::vector<T> t;

    BinTree1(size_t N) :
            size(N),
            t(2 * N) { }

    BinTree1(const std::vector<T>& other) :
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
        return std::max(left, right);
    }

    T init() {
        return 0;
    }
};

struct Solution {
    int n;
    std::vector<int> perm;
    std::vector<int> iperm;
    std::unique_ptr<BinTree1> tree;

    int get(int left, int right) {
        if (right - left <= 2) {
            return 0;
        }
        int maxV = tree->query(left, right);
        int pos = iperm[maxV];
        if (pos == left) {
            return get(left + 1, right);
        }
        if (pos == right - 1) {
            return get(left, right - 1);
        }
        int res = 0;
        if (pos - left < right - pos - 1) {
            for (int i = left; i < pos; i++) {
                int other = maxV - perm[i] - 1;
                int posOther = iperm[other];
                if (posOther > pos && posOther < right) {
                    res++;
                }
            }
        } else {
            for (int i = pos + 1; i < right; i++) {
                int other = maxV - perm[i] - 1;
                int posOther = iperm[other];
                if (posOther >= left && posOther < pos) {
                    res++;
                }
            }
        }
        return res + get(left, pos) + get(pos + 1, right);
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        perm.resize(n);
        iperm.resize(n);
        for (int i = 0; i < n; i++) {
            in >> perm[i];
            perm[i]--;
            iperm[perm[i]] = i;
        }
        tree.reset(new BinTree1(perm));
        int ans = get(0, n);
        out << ans << "\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}