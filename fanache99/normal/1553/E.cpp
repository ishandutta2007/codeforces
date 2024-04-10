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

const int MAXN = 300000;

int v[MAXN], p[MAXN], where[MAXN], w[MAXN];
int ok[MAXN];
bool seen[MAXN];

void DFS(int node) {
    seen[node] = true;
    if (!seen[w[node]]) {
        DFS(w[node]);
    }
}

bool check(int k, int n, int m) {
    for (int i = 0; i < n; i++) {
        p[i] = (i - k + n) % n;
        where[p[i]] = i;
        seen[i] = false;
    }
    int bad = 0;
    for (int i = 0; i < n; i++) {
        w[i] = where[v[i]];
        bad += (w[i] != i);
    }
    int cyc = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i] && w[i] != i) {
            DFS(i);
            cyc++;
        }
    }
    return (bad - cyc <= m);
}

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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i]--;
            ok[(i - v[i] + n) % n]++;
        }
        vector<int> sol;
        for (int i = 0; i < n; i++) {
            if (n - ok[i] <= 2 * m && check(i, n, m)) {
                sol.push_back(i);
            }
        }
        sort(sol.begin(), sol.end());
        cout << sol.size();
        for (auto it : sol) {
            cout << " " << it;
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            ok[i] = 0;
        }
    }
    return 0;
}