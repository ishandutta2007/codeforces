#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::string s;
    in >> s;
    std::string ans;
    int r = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (r > b) {
                ans.push_back('1');
                b++;
            } else {
                ans.push_back('0');
                r++;
            }
        } else {
            if (r > b) {
                ans.push_back('0');
                r--;
            } else {
                ans.push_back('1');
                b--;
            }
        }
    }
    out << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}