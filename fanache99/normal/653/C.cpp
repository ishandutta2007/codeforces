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

const int MAXN = 150000;

int v[1 + MAXN], n;
bool bad[1 + MAXN - 1];
vector<int> bads;

bool isBad(int i) {
    return i != 0 && i != n && ((i % 2 == 1 && v[i] >= v[i + 1]) || (i % 2 == 0 && v[i] <= v[i + 1]));
}

bool good(int a, int b) {
    for (auto i : bads) {
        if (i != a - 1 && i != a && i != b - 1 && i != b) {
            return false;
        }
    }
    swap(v[a], v[b]);
    bool ans = !isBad(a - 1) && !isBad(a) && !isBad(b - 1) && !isBad(b);
    swap(v[a], v[b]);
    return ans;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        bad[i] = isBad(i);
        if (bad[i]) {
            bads.push_back(i);
        }
    }
    assert(!bads.empty());
    if (bads.size() > 4) {
        cout << "0\n";
        return 0;
    }
    int pos = bads.back();
    int ans = good(pos, pos + 1);
    for (int i = 1; i <= n; i++) {
        if (i != pos && i != pos + 1) {
            ans += good(i, pos);
            ans += good(i, pos + 1);
        }
    }
    cout << ans << "\n";
    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}