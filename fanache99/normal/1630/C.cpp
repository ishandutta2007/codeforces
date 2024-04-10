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

int v[1 + MAXN], first[1 + MAXN], last[1 + MAXN], sum[1 + MAXN + 1];
bool ok[1 + MAXN];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (first[v[i]] == 0) {
            first[v[i]] = i;
        }
        last[v[i]] = i;
    }
    int rel = 0;
    for (int i = 1; i <= n; i++) {
        if (first[i] != 0) {
            assert(last[i] >= first[i]);
            if (first[i] < last[i]) {
                rel++;
                ok[first[i]] = ok[last[i]] = true;
                sum[first[i]]++;
                sum[last[i] + 1]--;
            }
        }
    }
    int ans = 2 * rel;
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] > 0 && !ok[i]) {
            ans++;
        }
        if (ok[i]) {
            p.push_back(v[i]);
        }
    }
    reverse(p.begin(), p.end());
    while (!p.empty()) {
        int x = p.back(), iters = 0;
        p.pop_back();
        while (true) {
            iters++;
            int best = 0, y;
            while (p.back() != x) {
                if (last[p.back()] > best) {
                    best = last[p.back()];
                    y = p.back();
                }
                p.pop_back();
            }
            p.pop_back();
            if (best <= last[x]) {
                break;
            } else {
                x = y;
            }
        }
        ans -= iters + 1;
    }
    cout << ans << "\n";
    return 0;
}