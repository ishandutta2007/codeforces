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

void addAll(std::ostream& out, std::vector<int>& as, int k, int from, int to) {
    int count = (as[from] + k - 1) / k;
    if (count == 0) return;
    out << count << " " << (from + 1) << " " << (to + 1) << "\n";
    as[to] += as[from];
    as[from] = 0;
}

void run(std::istream &in, std::ostream &out) {
    int n, k, v;
    in >> n >> k >> v;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    int all = std::accumulate(as.begin(), as.end(), 0);
    if (all < v) {
        out << "NO\n";
        return;
    }
    std::vector<bool> dyn(k);
    std::vector<bool> dyn2(k);
    std::vector<int> prev(k);
    dyn[0] = true;
    for (int i = 0; i < n; i++) {
        dyn2 = dyn;
        for (int j = 0; j < k; j++) {
            int nj = (j + as[i]) % k;
            if (dyn[j] && !dyn2[nj]) {
                dyn2[nj] = true;
                prev[nj] = i;
            }
        }
        std::swap(dyn2, dyn);
    }
    if (!dyn[v % k]) {
        out << "NO\n";
        return;
    }
    out << "YES\n";
    std::vector<int> good;
    int cur = v % k;
    while (cur != 0) {
        int tank = prev[cur];
        good.push_back(tank);
        cur = (cur - (as[tank] % k) + k) % k;
    }
    std::sort(good.begin(), good.end());
    std::vector<int> notGood;
    for (int i = 0; i < n; i++) {
        auto it = std::lower_bound(good.begin(), good.end(), i);
        if (it == good.end() || *it != i) {
            notGood.push_back(i);
        }
    }
    int final;
    int other;
    if (good.empty()) {
        final = 0;
        other = 1;
    } else {
        final = good[0];
        other = final == 0 ? 1 : 0;
    }
    if (good.empty()) {
        for (int tank : notGood) {
            if (tank != other) {
                addAll(out, as, k, tank, other);
            }
        }
    } else {
        for (int tank : good) {
            if (tank != final) {
                addAll(out, as, k, tank, final);
            }
        }
        for (int tank : notGood) {
            if (tank != other) {
                addAll(out, as, k, tank, other);
            }
        }
    }
    if (as[final] < v) {
        out << (v - as[final]) / k << " " << (other + 1) << " " << (final + 1) << "\n";
    } else if (as[final] > v) {
        out << (as[final] - v) / k << " " << (final + 1) << " " << (other + 1) << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}