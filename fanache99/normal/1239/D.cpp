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

const int MAXN = 1000000;

vector<int> g[1 + MAXN], gt[1 + MAXN];
bool seen[1 + MAXN];
vector<int> nodes, sol;

void DFS(int node) {
    seen[node] = true;
    for (auto it : g[node]) {
        if (!seen[it]) {
            DFS(it);
        }
    }
    nodes.push_back(node);
}

void DFS2(int node) {
    seen[node] = false;
    sol.push_back(node);
    for (auto it : gt[node]) {
        if (seen[it]) {
            DFS2(it);
        }
    }
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            gt[b].push_back(a);
        }
        nodes.clear();
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                DFS(i);
            }
        }

        reverse(nodes.begin(), nodes.end());
        for (auto it : nodes) {
            if (seen[it]) {
                sol.clear();
                DFS2(it);
            }
        }

        if (sol.size() != n) {
            cout << "Yes\n" << sol.size() << " " << n - sol.size() << "\n";
            for (auto it : sol) {
                cout << it << " ";
                seen[it] = true;
            }
            cout << "\n";
            for (int i = 1; i <= n; i++) {
                if (!seen[i]) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        } else {
            cout << "No\n";
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            gt[i].clear();
            seen[i] = false;
        }
    }
    return 0;
}