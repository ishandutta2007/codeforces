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

const int MAXN = 2000;
const int INF = 1000000;
const long long INFLL = 1e18;

int a[1 + MAXN][1 + MAXN], d[2][1 + MAXN][1 + MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(int n, int m, int sx, int sy, int id) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[id][i][j] = INF;
        }
    }
    queue<pair<int, int> > q;
    d[id][sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x0 = x + dx[i], y0 = y + dy[i];
            if (x0 >= 1 && x0 <= n && y0 >= 1 && y0 <= m && a[x0][y0] != -1 && d[id][x0][y0] == INF) {
                d[id][x0][y0] = d[id][x][y] + 1;
                q.push({x0, y0});
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    BFS(n, m, 1, 1, 0);
    BFS(n, m, n, m, 1);
    long long answer = INFLL;
    if (d[0][n][m] != INF) {
        answer = min(answer, 1LL * c * d[0][n][m]);
    }
    long long first = INFLL, second = INFLL;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > 0) {
                if (d[0][i][j] != INF) {
                    first = min(first, 1LL * c * d[0][i][j] + a[i][j]);
                }
                if (d[1][i][j] != INF) {
                    second = min(second, 1LL * c * d[1][i][j] + a[i][j]);
                }
            }
        }
    }
    if (first != INFLL && second != INFLL) {
        answer = min(answer, first + second);
    }
    if (answer == INFLL) {
        answer = -1;
    }
    cout << answer << "\n";
    return 0;
}