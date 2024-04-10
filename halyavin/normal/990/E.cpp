#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n, m, k;
    in >> n >> m >> k;
    std::vector<bool> flags(n, true);
    for (int i = 0; i < m; i++) {
        int pos;
        in >> pos;
        flags[pos] = false;
    }
    if (!flags[0]) {
        out << "-1\n";
        return;
    }
    std::vector<int64_t> as(k);
    for (int i = 0; i < k; i++) {
        in >> as[i];
    }
    std::vector<int> prev(n);
    int tmp = 0;
    for (int i = 1; i < n; i++) {
        if (flags[i]) {
            tmp = i;
        }
        prev[i] = tmp;
    }
    int64_t ans = int64_t(1) << 60;
    for (int i = 1; i <= k; i++) {
        int64_t cost = as[i - 1];
        int pos = 0;
        int lamps = 1;
        while (pos + i < n) {
            if (flags[pos + i]) {
                pos += i;
                lamps++;
                continue;
            }
            int nextPos = prev[pos + i];
            if (nextPos <= pos) {
                lamps = 0;
                break;
            }
            pos = nextPos;
            lamps++;
        }
        if (lamps == 0) continue;
        ans = std::min(ans, lamps * cost);
    }
    if (ans == int64_t(1) << 60) {
        out << "-1\n";
    } else {
        out << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}