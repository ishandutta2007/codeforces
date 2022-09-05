#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n, a, b;
    in >> n >> a >> b;
    if (a > 1 && b > 1) {
        out << "NO\n";
        return;
    }
    if (a == 1 && b == 1) {
        if (n == 1) {
            out << "YES\n";
            out << "0\n";
            return;
        }
        if (n == 2 || n == 3) {
            out << "NO\n";
            return;
        }
        out << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i - j == 1 || j - i == 1) {
                    out << "1";
                } else {
                    out << "0";
                }
            }
            out << "\n";
        }
        return;
    }
    if (a == 1) {
        out << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || (i <= n - b && j <= n - b)) {
                    out << "0";
                } else {
                    out << "1";
                }
            }
            out << "\n";
        }
    } else {
        out << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= n - a && j <= n - a && i != j) {
                    out << "1";
                } else {
                    out << "0";
                }
            }
            out << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}