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
const long long INF = 1e12;

vector<pair<int, int> > g[1 + MAXN];
long long bad, good[1 + MAXN][2];
int n, weight[1 + MAXN];

void DFS(int node, int father) {
    weight[node] = 1;
    long long sum = 0;
    good[node][0] = INF;
    vector<long long> delta;
    for (auto it : g[node]) {
        int son = it.first, l = it.second;
        if (son != father) {
            DFS(son, node);
            weight[node] += weight[son];
            bad += 1LL * l * min(weight[son], n - weight[son]);
            sum += good[son][0];
            delta.push_back(good[son][1] - good[son][0] + l);
        }
    }
    sort(delta.begin(), delta.end());
    good[node][1] = sum;
    for (int i = 0; i + 1 < delta.size() && delta[i] + delta[i + 1] < 0; i += 2) {
        good[node][1] += delta[i] + delta[i + 1];
    }
    good[node][0] = (delta.size() == 0 ? INF : sum + delta[0]);
    for (int i = 1; i + 1 < delta.size() && delta[i] + delta[i + 1] < 0; i += 2) {
        good[node][0] += delta[i] + delta[i + 1];
    }
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
        cin >> n;
        n *= 2;
        for (int i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        bad = 0;
        DFS(1, 0);
        cout << good[1][0] << " " << bad << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}