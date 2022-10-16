#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MOD = 1000000009;
const int BASE = 73;

string longest(string &s) {
    int a = 0, b = 0, answer = 0, power = 1;
    for (int i = 0; i < s.size(); i++) {
        a = (1LL * a * BASE + s[i] - 'a' + 1) % MOD;
        b = (1LL * (s[i] - 'a' + 1) * power + b) % MOD;
        power = 1LL * BASE * power % MOD;
        if (a == b)
            answer = i + 1;
    }
    return s.substr(0, answer);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        string s;
        cin >> s;
        int n = s.size(), a = 0, b = n - 1;
        while (a < b && s[a] == s[b]) {
            a++;
            b--;
        }
        string t = s.substr(a, b - a + 1), prefix = s.substr(0, a), suffix = s.substr(b + 1, n - b);
        string bestPrefix = longest(t);
        reverse(t.begin(), t.end());
        string bestSuffix = longest(t);
        if (bestPrefix.size() > bestSuffix.size())
            cout << prefix + bestPrefix + suffix << "\n";
        else
            cout << prefix + bestSuffix + suffix << "\n";
    }
    return 0;
}