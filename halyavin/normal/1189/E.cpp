#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

void run(std::istream &in, std::ostream &out) {
    int n, k, p;
    in >> n >> p >> k;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::map<int, int> stat;
    for (int i = 0; i < n; i++) {
        stat[as[i] % p]++;
    }
    int64_t res = 0;
    std::map<int, int> stat2;
    for (const auto &entry : stat) {
        int v = entry.first;
        int v2 = (v + v) % p;
        int vv = int64_t(v) * v % p;
        int vv2 = (vv + vv) % p;
        int all = int64_t(v2) * vv2 % p;
        if (all != k) {
            res -= (int64_t(entry.second) * (entry.second - 1)) / 2;
        }
        int v4 = int64_t(vv) * vv % p;
        int kv = int64_t(v) * k % p;
        int key = (v4 - kv + p) % p;
        for (int i = 0; i < entry.second; i++) {
            res += stat2[key];
            stat2[key]++;
        }
    }
    out << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}