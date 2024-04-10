#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

const int p = 998244353;

int add32(int x, int y) {
    int res = x + y;
    if (res >= p) res -= p;
    return res;
}

int mul32(int x, int y) {
    return int64_t(x) * y % p;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    int d = 0;
    int sum = 0;
    int sumPow = 0;
    int dyn = 0;
    for (int i = 1; i <= n; i++) {
        sumPow = add32(sumPow, sumPow);
        sumPow = add32(sumPow, as[i - 1]);
        dyn = add32(sum, sumPow);
        sum = add32(sum, dyn);
    }
    out << dyn << "\n";


}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}