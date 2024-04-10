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

const int MAXN = 200000;

int v[MAXN];

vector<int> divisors(int n) {
    vector<int> ans;
    int cn = n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(cn / i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    return ans;
}

int main() {
    //  ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, q;
        cin >> n >> q;
        vector<int> divs = divisors(n);
        vector<vector<long long>> sum(divs.size());
        vector<vector<int>> last(divs.size());
        vector<priority_queue<tuple<long long, int, int>>> mx(divs.size());
        for (int i = 0; i < divs.size(); i++) {
            sum[i].resize(divs[i]);
            last[i].resize(divs[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = 0; j < divs.size(); j++) {
                sum[j][i % divs[j]] += v[i];
            }
        }
        for (int j = 0; j < divs.size(); j++) {
            for (int i = 0; i < divs[j]; i++) {
                mx[j].push({sum[j][i], i, 0});
            }
        }

        auto getBest = [&]() {
            long long best = 0;
            for (int j = 0; j < divs.size(); j++) {
                while (get<2>(mx[j].top()) < last[j][get<1>(mx[j].top())]) {
                    mx[j].pop();
                }
                best = max(best, get<0>(mx[j].top()) * divs[j]);
            }
            return best;
        };

        cout << getBest() << "\n";
        for (int i = 1; i <= q; i++) {
            int p, x;
            cin >> p >> x;
            p--;
            for (int j = 0; j < divs.size(); j++) {
                int r = p % divs[j];
                sum[j][r] += x - v[p];
                last[j][r] = i;
                mx[j].push({sum[j][r], r, i});
            }
            v[p] = x;
            cout << getBest() << "\n";
        }
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}