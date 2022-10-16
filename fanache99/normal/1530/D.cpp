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

const int MAXN = 200000;

int v[1 + MAXN], p[1 + MAXN], q[1 + MAXN];
vector<int> g[1 + MAXN];

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
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            p[i] = q[i] = 0;
            g[v[i]].push_back(i);
        }
        vector<int> in;
        for (int i = 1; i <= n; i++) {
            if (!g[i].empty()) {
                p[g[i].back()] = i;
                q[i] = g[i].back();
            } else {
                in.push_back(i);
            }
        }
        vector<int> out;
        for (int i = 1; i <= n; i++) {
            if (p[i] == 0) {
                out.push_back(i);
            }
        }
        assert(out.size() == in.size());
        for (int i = 0; i < in.size(); i++) {
            p[out[i]] = in[i];
            q[in[i]] = out[i];
        }
        vector<int> bad;
        for (int i = 1; i <= n; i++) {
            if (p[i] == i) {
                bad.push_back(i);
            }
        }
        if (!bad.empty()) {
            if (bad.size() == 1) {
                int x = bad.back(), y = v[x];
                q[x] = q[y];
                p[q[y]] = x;
                p[x] = y;
                q[y] = x;
            } else {
                for (int i = 0; i < bad.size(); i++) {
                    int x = bad[i], y = bad[(i + 1) % bad.size()];
                    p[x] = y;
                    q[y] = x;
                }
            }
        }
        cout << n - in.size() << "\n";
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            cout << p[i] << " ";
            tot += p[i] == v[i];
            assert(p[i] != i);
        }
        assert(tot == n - in.size());
        cout << "\n";
    }
    return 0;
}