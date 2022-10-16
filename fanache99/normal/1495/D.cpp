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

clock_t timeStart, timecinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timecinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timecinish - timeStart) / double(CLOCKS_PER_SEC);
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
    inline InputReader &operator >>(long long &n) {
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

const int MAXN = 400;
const int MAXM = 600;
const int MOD = 998244353;

vector<int> g[1 + MAXN];
int d[1 + MAXN][1 + MAXN];
int answer[1 + MAXN][1 + MAXN];
bool path[1 + MAXN];

void BFS(int start, int n) {
    for (int i = 1; i <= n; i++) {
        d[start][i] = n + 1;
    }
    d[start][start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : g[node]) {
            if (d[start][it] > d[start][node] + 1) {
                d[start][it] = d[start][node] + 1;
                q.push(it);
            }
        }
    }
}

int oneSource(int x, int n) {
    int answer = 1;
    for (int i = 1; i <= n; i++) {
        if (d[x][i] != 0) {
            int dads = 0;
            for (auto j : g[i]) {
                if (d[x][j] + 1 == d[x][i]) {
                    dads++;
                }
            }
            answer = 1LL * answer * dads % MOD;
        }
    }
    return answer;
}

int twoSources(int x, int y, int n) {
    int l = d[x][y];
    for (int i = 0; i <= l; i++) {
        path[i] = false;
    }
    int answer = 1;
    for (int i = 1; i <= n; i++) {
        int diff = d[x][i] - d[y][i] + l;
        if (diff % 2 != 0) {
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        int pi = (d[x][i] - d[y][i] + l) / 2;
        int di = d[x][i] - pi;
        if (di == 0) {
            if (path[d[x][i]]) {
                return 0;
            }
            path[d[x][i]] = true;
        } else {
            int dads = 0;
            for (auto j : g[i]) {
                int pj = (d[x][j] - d[y][j] + l) / 2;
                int dj = d[x][j] - pj;
                if (pi == pj && dj + 1 == di) {
                    dads++;
                }
            }
            answer = 1LL * answer * dads % MOD;
        }
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        BFS(i, n);
    }
    for (int i = 1; i <= n; i++) {
        answer[i][i] = oneSource(i, n);
        for (int j = i + 1; j <= n; j++) {
            answer[i][j] = answer[j][i] = twoSources(i, j, n);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
    //timeDuration();
    return 0;
}