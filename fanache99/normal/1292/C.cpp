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

const int MAXN = 3000;

vector<int> g[1 + MAXN];
long long dp[1 + MAXN][1 + MAXN];
int n, dad[1 + MAXN], weight[1 + MAXN], start[1 + MAXN], depth[1 + MAXN], finish[1 + MAXN], id = 0;

void DFS(int node, int father) {
    dad[node] = father;
    weight[node] = 1;
    depth[node] = depth[father] + 1;
    start[node] = ++id;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            weight[node] += weight[son];
        }
    }
    finish[node] = id;
}

bool isAncestor(int a, int b) {
    return start[a] <= start[b] && finish[b] <= finish[a];
}

long long compute(int a, int b) {
    if (a == b || dp[a][b] != 0) {
        return dp[a][b];
    }
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    long long answer = 0;
    if (isAncestor(a, b)) {
        int c;
        for (auto it : g[a]) {
            if (depth[it] > depth[a] && isAncestor(it, b)) {
                c = it;
                break;
            }
        }
        answer += (n - weight[c]) * weight[b];
        answer += max(compute(c, b), compute(a, dad[b]));
    } else {
        answer += weight[a] * weight[b];
        answer += max(compute(dad[a], b), compute(a, dad[b]));
    }
    dp[a][b] = dp[b][a] = answer;
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            answer = max(answer, compute(i, j));
        }
    }
    cout << answer << "\n";
    return 0;
}