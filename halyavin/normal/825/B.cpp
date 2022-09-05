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

void run(std::istream& in, std::ostream& out) {
    std::vector<std::string> field(10);
    for (int i = 0; i < 10; i++) {
        in >> field[i];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= 5; j++) {
            int stat = 0;
            int empty = 0;
            for (int k = 0; k < 5; k++) {
                if (field[i][j + k] == 'X') {
                    stat++;
                } else if (field[i][j + k] == '.') {
                    empty++;
                }
            }
            if (stat == 4 && empty == 1) {
                out << "YES\n";
                return;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= 5; j++) {
            int stat = 0;
            int empty = 0;
            for (int k = 0; k < 5; k++) {
                if (field[j + k][i] == 'X') {
                    stat++;
                } else if (field[j + k][i] == '.') {
                    empty++;
                }
            }
            if (stat == 4 && empty == 1) {
                out << "YES\n";
                return;
            }
        }
    }

    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            int stat = 0;
            int empty = 0;
            for (int k = 0; k < 5; k++) {
                if (field[i + k][j + k] == 'X') {
                    stat++;
                } else if (field[i + k][j + k] == '.') {
                    empty++;
                }
            }
            if (stat == 4 && empty == 1) {
                out << "YES\n";
                return;
            }
        }
    }

    for (int i = 0; i <= 5; i++) {
        for (int j = 4; j < 10; j++) {
            int stat = 0;
            int empty = 0;
            for (int k = 0; k < 5; k++) {
                if (field[i + k][j - k] == 'X') {
                    stat++;
                } else if (field[i + k][j - k] == '.') {
                    empty++;
                }
            }
            if (stat == 4 && empty == 1) {
                out << "YES\n";
                return;
            }
        }
    }
    out << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}