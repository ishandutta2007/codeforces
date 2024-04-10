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
const int INF = 1000000001;

int a[1 + MAXN], b[1 + MAXN];
vector<int> g[1 + MAXN];
bool taken[1 + MAXN];
int dad[1 + MAXN], total;
long long power;
bool found;

void take(int node) {
    while (dad[node] != node) {
        if (!taken[node]) {
            taken[node] = true;
            total++;
            power += b[node];
        }
        node = dad[node];
    }
}

void DFS(int node, long long current) {
    for (auto neighbour : g[node]) {
        if (dad[neighbour] != 0 && neighbour != dad[node] && (!taken[node] || !taken[neighbour])) {
            found = true;
            take(node);
            take(neighbour);
            return;
        }
        if (dad[neighbour] == 0 && current > a[neighbour]) {
            dad[neighbour] = node;
            DFS(neighbour, current + b[neighbour]);
        }
        if (found) {
            return;
        }
    }
}

bool check(int n, int start) {
    for (int i = 1; i <= n; i++) {
        taken[i] = false;
    }
    taken[1] = true;
    total = 1;
    power = start;
    while (total < n) {
        for (int i = 1; i <= n; i++) {
            if (taken[i]) {
                dad[i] = i;
            } else {
                dad[i] = 0;
            }
        }
        found = false;
        for (int i = 1; i <= n && !found; i++) {
            if (taken[i]) {
                DFS(i, power);
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
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
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 2; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int left = 1, right = INF, answer = INF;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (check(n, middle)) {
                answer = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        cout << answer << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}