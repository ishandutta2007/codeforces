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

void run(std::istream &in, std::ostream &out) {
    int h1, c1, a1;
    int h2, a2;
    in >> h1 >> a1 >> c1;
    in >> h2 >> a2;
    int heals = 0;
    int strikes = (h2 + a1 - 1) / a1;
    int health = h1 - a2 * (strikes - 1);
    while (health <= 0) {
        heals++;
        health += c1 - a2;
    }
    out << heals + strikes << std::endl;
    for (int i = 0; i < heals; i++) {
        out << "HEAL\n";
    }
    for (int i = 0; i < strikes; i++) {
        out << "STRIKE\n";
    }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}