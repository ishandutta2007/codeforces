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

const int MAXN = 1000;
const int MOD = 998244353;

char s[1 + MAXN];
vector<int> same[1 + 2 * MAXN + 2], diff[1 + 2 * MAXN + 2];
int compId[1 + 2 * MAXN + 2], pow2[1 + 2 * MAXN + 2], color[1 + 2 * MAXN + 2];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void DFS(int node, int comp) {
    compId[node] = comp;
    for (auto it : same[node]) {
        if (!compId[it]) {
            DFS(it, comp);
        }
    }
}

void DFS2(int node, bool &bad, int col) {
    color[node] = col;
    for (auto it : diff[node]) {
        if (!color[it]) {
            DFS2(it, bad, 3 - col);
        } else {
            bad |= (color[it] == color[node]);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> (s + 1);
    int n = strlen(s + 1);
    if (n == 1) {
        cout << "0\n";
    } else {
        pow2[0] = 1;
        for (int i = 1; i <= 2 * n + 2; i++) {
            pow2[i] = pow2[i - 1];
            add(pow2[i], pow2[i]);
        }
        int ans = 0;
        for (int l = 1; l < n; l++) {
            for (int i = 1; i < n - i + 1; i++) {
                same[i].push_back(n - i + 1);
                same[n - i + 1].push_back(i);
            }
            for (int i = 1; i < l - i + 1; i++) {
                same[n + i].push_back(n + l - i + 1);
                same[n + l - i + 1].push_back(n + i);
            }
            for (int i = 1; i <= n; i++) {
                if (s[i] == '0') {
                    int j = (i >= n - l + 1 ? n + i - (n - l + 1) + 1 : n + l + 1);
                    same[i].push_back(j);
                    same[j].push_back(i);
                }
            }
            int comp = 0;
            for (int i = 1; i <= n + l + 2; i++) {
                if (!compId[i]) {
                    DFS(i, ++comp);
                }
            }
            diff[compId[n + l + 1]].push_back(compId[n + 1]);
            diff[compId[n + 1]].push_back(compId[n + l + 1]);
            diff[compId[n + l + 1]].push_back(compId[n + l + 2]);
            diff[compId[n + l + 2]].push_back(compId[n + l + 1]);
            for (int i = 1; i <= n; i++) {
                if (s[i] == '1') {
                    int j = (i >= n - l + 1 ? n + i - (n - l + 1) + 1 : n + l + 1);
                    diff[compId[i]].push_back(compId[j]);
                    diff[compId[j]].push_back(compId[i]);
                }
            }
            bool bad = false;
            int tot = 0;
            for (int i = 1; i <= comp; i++) {
                if (!color[i]) {
                    tot++;
                    DFS2(i, bad, 1);
                }
            }
            if (!bad) {
                add(ans, pow2[tot - 1]);
            }
            for (int i = 1; i <= n + l + 2; i++) {
                same[i].clear();
                diff[i].clear();
                compId[i] = color[i] = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}