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

const int MAXN = 100000;

set<int> g[MAXN];
int depth[1 + MAXN], dad[1 + MAXN];

void DFS(int node) {
    for (auto son : g[node]) {
        depth[son] = depth[node] + 1;
        DFS(son);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> dad[i];
        g[dad[i]].insert(i);
    }
    DFS(0);
    int deepest = 0;
    for (int i = 1; i < n; i++) {
        if (depth[i] > depth[deepest]) {
            deepest = i;
        }
    }
    vector<int> path, sol;
    path.push_back(deepest);
    while (path.back() != 0) {
        int node = path.back();
        if (g[dad[node]].size() == 1) {
            path.push_back(dad[node]);
        } else {
            g[dad[node]].erase(node);
            int other = *g[dad[node]].begin();
            sol.push_back(node);
            dad[node] = other;
            g[other].insert(node);
        }
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    reverse(sol.begin(), sol.end());
    assert(sol.size() == n - 1 - depth[deepest]);
    cout << "\n" << sol.size() << "\n";
    for (auto it : sol) {
        cout << it << " ";
    }
    return 0;
}