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
#include <array>

int getScore(int a, int b) {
    if (a == b) return 0;
    if ((a - b + 3) % 3 == 1) return 1;
    return 0;
}

void run(std::istream &in, std::ostream &out) {
    int64_t k;
    int a, b;
    in >> k >> a >> b;
    a--;
    b--;
    std::array<std::array<int, 3>, 3> alice, bob;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            in >> alice[i][j];
            alice[i][j]--;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            in >> bob[i][j];
            bob[i][j]--;
        }
    }
    int64_t scoreAlice = 0;
    int64_t scoreBob = 0;
    int maxPeriod = 9 * 8 * 7 * 5;
    if (k < 4 * maxPeriod) {
        for (int round = 0; round < k; round++) {
            scoreAlice += getScore(a, b);
            scoreBob += getScore(b, a);
            int na = alice[a][b];
            int nb = bob[a][b];
            a = na;
            b = nb;
        }
    } else {
        int round = 0;
        for (; round < (k % maxPeriod) + maxPeriod; round++) {
            scoreAlice += getScore(a, b);
            scoreBob += getScore(b, a);
            int na = alice[a][b];
            int nb = bob[a][b];
            a = na;
            b = nb;
        }
        int periodAlice = 0;
        int periodBob = 0;
        for (int i = 0; i < maxPeriod; i++) {
            periodAlice += getScore(a, b);
            periodBob += getScore(b, a);
            int na = alice[a][b];
            int nb = bob[a][b];
            a = na;
            b = nb;
        }
        scoreAlice += periodAlice * ((k - round) / maxPeriod);
        scoreBob += periodBob * ((k - round) / maxPeriod);
    }
    out << scoreAlice << " " << scoreBob << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}