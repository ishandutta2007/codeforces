#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>


void run(std::istream& in, std::ostream& out) {
    int tests;
    in >> tests;
    for (int test = 0; test < tests; test++) {
        int n;
        in >> n;
        int halfn = n / 2;
        std::vector<std::array<int, 5>> students(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                in >> students[i][j];
            }
        }
        bool found = false;
        for (int first = 0; first < 5 && !found; first++) {
            for (int second = first + 1; second < 5; second++) {
                int A = 0;
                int B = 0;
                int C = 0;
                for (const auto& student : students) {
                    if (student[first] > 0) {
                        if (student[second] > 0) {
                            C++;
                        } else {
                            A++;
                        }
                    } else if (student[second] > 0) {
                        B++;
                    } else {
                        break;
                    }
                }
                if (A + B + C < n) {
                    continue;
                }
                if (A + C >= halfn && B + C >= halfn) {
                    found = true;
                    out << "YES\n";
                    break;
                }
            }
        }
        if (!found) {
            out << "NO\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}