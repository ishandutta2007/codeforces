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

const int MAXN = 300000;

set<pair<int, int>> bad;

bool isBad(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return bad.find({a, b}) != bad.end();
}

set<int> notVis;
int deg[1 + MAXN];

void DFS(int node) {
    notVis.erase(node);
    int next = 0;
    while (true) {
        auto it = notVis.upper_bound(next);
        if (it == notVis.end()) {
            break;
        }
        next = *it;
        if (isBad(node, next)) {
            continue;
        }
        DFS(next);
    }
}

int getLow(int n) {
    for (int i = 2; i <= n; i++) {
        notVis.insert(i);
    }
    int comps = 0;
    for (int i = 2; i <= n; i++) {
        if (notVis.find(i) != notVis.end()) {
            DFS(i);
            comps++;
        }
    }
    return comps;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        bad.insert({a, b});
        deg[a]++;
        deg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        notVis.insert(i);
    }
    DFS(1);
    if (!notVis.empty()) {
        cout << "impossible\n";
        return 0;
    }

    int low = getLow(n), high = n - 1 - deg[1];
    if (low <= k && k <= high) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}