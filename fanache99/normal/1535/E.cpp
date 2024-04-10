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
#include <unordered_map>
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

const int MAXN = 300000;
const int MAXLOG = 20;

int v[1 + MAXN], c[1 + MAXN];
vector<int> g[1 + MAXN];
bool out[1 + MAXN];
int dad[1 + MAXN][1 + MAXLOG], depth[1 + MAXN];

int findStart(int node) {
    for (int i = MAXLOG; i >= 0; i--) {
        if (!out[dad[node][i]]) {
            node = dad[node][i];
        }
    }
    return node;
}

int findAncestor(int node, int delta) {
    for (int i = MAXLOG; i >= 0; i--) {
        if ((delta >> i) & 1) {
            node = dad[node][i];
        }
    }
    return node;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int q;
    cin >> q >> v[0] >> c[0];
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            cin >> p >> v[i] >> c[i];
            depth[i] = depth[p] + 1;
            dad[i][0] = p;
            for (int j = 1; j <= MAXLOG; j++) {
                dad[i][j] = dad[dad[i][j - 1]][j - 1];
            }
        } else {
            int x, w;
            cin >> x >> w;
            int y = findStart(x);
            int s = 0;
            long long t = 0;
            while (true) {
                int r = min(w - s, v[y]);
                t += 1LL * r * c[y];
                v[y] -= r;
                s += r;
                if (v[y] == 0) {
                    out[y] = true;
                }
                if (x == y || s == w) {
                    break;
                }
                y = findAncestor(x, depth[x] - depth[y] - 1);
            }
            cout << s << " " << t << "\n";
            cout.flush();
        }
    }
    return 0;
}