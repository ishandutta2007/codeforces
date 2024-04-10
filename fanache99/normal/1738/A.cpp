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

int a[1 + MAXN], b[1 + MAXN];

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
            cin >> a[i];
        }
        vector<vector<int>> v(2);
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            sum += b[i];
            v[a[i]].push_back(b[i]);
        }
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());
        reverse(v[0].begin(), v[0].end());
        reverse(v[1].begin(), v[1].end());

        auto maybe = [&]() -> long long {
            long long ans = 0;
            for (int i = 0; i < min((int) v[0].size(), (int) v[1].size()); i++) {
                ans += v[1][i];
            }
            for (int i = 0; i < min(int(v[0].size()) - 1, (int) v[1].size()); i++) {
                ans += v[0][i];
            }
            return ans;
        };
        long long ans = maybe();
        swap(v[0], v[1]);
        ans = max(ans, maybe());
        cout << ans + sum << "\n";
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}