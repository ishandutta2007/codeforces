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
#include <random>

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

const int MAXN = 100000;

int b[1 + MAXN], bt[1 + MAXN];
vector<int> v[1 + MAXN + 1];

void check(const vector<int> &a, int k) {
    int lastSmall = 0, lastBig = a.size() + 1;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        if (x <= k) {
            bt[x] = lastBig;
            lastSmall = x;
        } else {
            bt[x] = lastSmall;
            lastBig = x;
        }
    }
    for (int i = 1; i <= a.size(); i++) {
        assert(bt[i] == b[i]);
    }
}

int main() {
    // ifstream cin("input.txt");
//    ofstream cout("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            v[b[i]].push_back(i);
        }
        assert(!(v[0].empty() && v[n + 1].empty()));
        assert(v[0].empty() || v[n + 1].empty());
        int curr = v[0].empty() ? n + 1 : 0;
        bool small = v[0].empty() ? true : false;
        int k = 0;
        vector<int> a;
        while (true) {
            int last, found = 0;
            for (auto x : v[curr]) {
                if (!v[x].empty()) {
                    last = x;
                    found++;
                }
            }
            if (found == 0) {
                break;
            }
            assert(found == 1);
            for (auto x : v[curr]) {
                if (small) {
                    k = max(k, x);
                }
                if (x != last) {
                    a.push_back(x);
                }
            }
            small ^= 1;
            a.push_back(last);
            curr = last;
        }
        for (auto x : v[curr]) {
            if (small) {
                k = max(k, x);
            }
            a.push_back(x);
        }
        cout << k << "\n";
        for (auto x : a) {
            cout << x << " ";
        }
        check(a, k);
        cout << "\n";
        for (int i = 0; i <= n + 1; i++) {
            v[i].clear();
        }
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}