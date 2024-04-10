#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <vector>

const int N = 10000;

bool valid[N][4];

int main()
{
    std::string s;
    std::cin >> s;
    std::set<std::string> result;
    int n = s.length();
    memset(valid, 0, sizeof(valid));
    for (int i = n - 1; i >= 0; -- i) {
        for (int l = 2; l <= 3; ++ l) {
            if (i + l == n) {
                valid[i][l] = true;
            } else {
                for (int l2 = 2; l2 <= 3; ++ l2) {
                    if (i + l + l2 <= n && s.substr(i, l) != s.substr(i + l, l2)) {
                        valid[i][l] |= valid[i + l][l2];
                    }
                }
            }
            if (valid[i][l] && i >= 5) {
                result.insert(s.substr(i, l));
            }
        }
    }
    printf("%d\n", (int)result.size());
    for(auto&& suffix : result) {
        std::cout << suffix << std::endl;
    }
}