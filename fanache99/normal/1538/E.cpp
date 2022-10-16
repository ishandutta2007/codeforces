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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

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

    inline InputReader &operator>>(int &n) {
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

int haha(string &s) {
    int ans = 0;
    for (int i = 0; i + 4 <= s.size(); i++) {
        if (s[i] == 'h' && s[i + 1] == 'a' && s[i + 2] == 'h' && s[i + 3] == 'a') {
            ans++;
        }
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        map<string, string> val;
        map<string, long long> f;
        string last;
        for (int i = 1; i <= n; i++) {
            string x, type;
            last = x;
            cin >> x >> type;
            last = x;
            if (type == ":=") {
                string s;
                cin >> s;
                val[x] = s;
                f[x] = haha(s);
            } else {
                string a, b;
                cin >> a >> type >> b;
                long long fa = f[a], fb = f[b];
                string sa = val[a], sb = val[b];
                string s = sa.substr(max((int) sa.size() - 3, 0), min(3, (int) sa.size())) + sb.substr(0, min(3, (int) sb.size()));
                f[x] = fa + fb + haha(s);
                s = sa + sb;
                if (s.size() > 6) {
                    sa = s.substr(0, 3);
                    sb = s.substr(s.size() - 3, 3);
                    s = sa + sb;
                }
                val[x] = s;
            }
        }
        cout << f[last] << "\n";
    }
    return 0;
}