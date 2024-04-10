#include <iostream>
#include <vector>
#include <algorithm>

void run(std::istream &in, std::ostream &out) {
    std::string str;
    in >> str;
    size_t n = str.length();
    std::vector<int> pi(n + 1);
    pi[0] = -1;
    for (size_t i = 1; i <= n; i++) {
        int v = pi[i - 1];
        while (v >= 0 && str[v] != str[i - 1]) {
            v = pi[v];
        }
        pi[i] = v + 1;
    }
    std::string rstr = str;
    std::reverse(rstr.begin(), rstr.end());
    int cur_pi = 0;
    int rev_pos;
    for (rev_pos = 0; rev_pos < n; rev_pos++) {
        while (cur_pi >= 0 && rstr[rev_pos] != str[cur_pi]) {
            cur_pi = pi[cur_pi];
        }
        cur_pi++;
    }
    std::vector<int> palindromes(2 * cur_pi + 2);
    int64_t answer = 0;
    while (cur_pi > 0) {
        palindromes[cur_pi] = 1 + palindromes[2 * cur_pi] + palindromes[2 * cur_pi+1];
        answer += palindromes[cur_pi];
        cur_pi = pi[cur_pi];
    }
    out << answer << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}