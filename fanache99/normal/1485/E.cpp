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

const int MAXN = 200000;
const long long INF = 1000000000000000000LL;

int v[1 + MAXN];
vector<int> g[1 + MAXN];
int dad[1 + MAXN], depth[1 + MAXN];
long long dp[1 + MAXN];
vector<int> l[1 + MAXN];
int dMax;

void DFS(int node, int father) {
    dad[node] = father;
    depth[node] = depth[father] + 1;
    l[depth[node]].push_back(node);
    dMax = max(dMax, depth[node]);
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
        }
    }
}

bool cmp(int a, int b) {
    return v[a] < v[b];
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            g[p].push_back(i);
            g[i].push_back(p);
        }
        for (int i = 2; i <= n; i++) {
            cin >> v[i];
        }
        dMax = 0;
        DFS(1, 0);
        for (int i = 2; i <= dMax; i++) {
            sort(l[i].begin(), l[i].end(), cmp);
            long long best = -INF;
            for (auto node : l[i]) {
                dp[node] = dp[dad[node]] + max(v[node] - v[l[i][0]], v[l[i].back()] - v[node]);
                best = max(best, dp[dad[node]] - v[node]);
                dp[node] = max(dp[node], v[node] + best);
            }
            reverse(l[i].begin(), l[i].end());
            best = -INF;
            for (auto node : l[i]) {
                best = max(best, dp[dad[node]] + v[node]);
                dp[node] = max(dp[node], best - v[node]);
            }
        }
        long long answer = 0;
        for (auto node : l[dMax]) {
            answer = max(answer, dp[node]);
        }
        cout << answer << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            l[i].clear();
        }
    }
    //timeDuration();
    return 0;
}