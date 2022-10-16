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
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 600;
const int INF = 1e9 + 1e5;

vector<pair<int, int> > g[MAXN];
int d[MAXN];
vector<int> l[MAXN];
bool out[MAXN];

void transit(int c, int n, int i, int j, int t) {
    if (d[i] + t < d[j]) {
        d[j] = d[i] + t;
        if (d[j] - c < n) {
            l[d[j] - c].push_back(j);
        }
    }
}

void solve(int s, int n) {
    int c = INF;
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        out[i] = false;
        l[i].clear();
    }
    for (auto it : g[s]) {
        c = min(c, it.second);
    }
    for (auto it : g[s]) {
        int j = it.first;
        d[j] = min(d[j], it.second);
    }
    for (int i = 0; i < n; i++) {
        if (d[i] - c < n) {
            l[d[i] - c].push_back(i);
        }
    }
    for (int x = 0; x < n; x++) {
        for (auto i : l[x]) {
            if (!out[i]) {
                out[i] = true;
                transit(c, n, i, (i + 1) % n, 1);
                for (auto it : g[i]) {
                    int j = it.first;
                    transit(c, n, i, (j + d[i]) % n, it.second);
                }
            }
        }
    }
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        solve(i, n);
    }
    return 0;
}