#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>

using namespace std;
using namespace std::chrono;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int SIGMA = 6;

int go[SIGMA][SIGMA];
int ans = 0;

bool check(string s) {
    while (s.size() > 1) {
        int n = s.size();
        if (go[s[n - 1]][s[n - 2]] == -1) {
            return false;
        }
        int ch = go[s[n - 1]][s[n - 2]];
        s.pop_back();
        s.pop_back();
        s.push_back(ch);
    }
    return s[0] == 0;
}

void generate(int n, string s) {
    if (n == 0) {
        ans += check(s);
        return;
    }
    for (int i = 0; i < SIGMA; i++) {
        generate(n - 1, s + (char) i);
    }
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < SIGMA; i++) {
        for (int j = 0; j < SIGMA; j++) {
            go[i][j] = -1;
        }
    }
    for (int i = 1; i <= q; i++) {
        string a, b;
        cin >> a >> b;
        go[a[0] - 'a'][a[1] - 'a'] = b[0] - 'a';
    }
    generate(n, "");
    cout << ans << "\n";
    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}