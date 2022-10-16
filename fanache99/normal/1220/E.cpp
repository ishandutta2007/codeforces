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

vector<int> g[1 + MAXN];
int v[1 + MAXN];
int degree[1 + MAXN];
bool out[1 + MAXN], seen[1 + MAXN];
long long dp[1 + MAXN];

long long DFS(int node, int father) {
    dp[node] = 0;
    for (auto other : g[node]) {
        if (out[other] && other != father) {
            dp[node] = max(dp[node], DFS(other, node));
        }
    }
    dp[node] += v[node];
    return dp[node];
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    int s;
    cin >> s;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1 && i != s) {
            q.push(i);
            out[i] = true;
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto other : g[node]) {
            if (!out[other]) {
                degree[other]--;
                if (degree[other] == 1 && other != s) {
                    q.push(other);
                    out[other] = true;
                }
            }
        }
    }
    long long answer = 0, best = 0;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            answer += v[i];
        } else {
            bool found = false;
            for (auto j : g[i]) {
                if (!out[j]) {
                    found = true;
                }
            }
            if (found) {
                best = max(best, DFS(i, 0));
            }
        }
    }
    cout << answer + best << "\n";
    //timeDuration();
    return 0;
}