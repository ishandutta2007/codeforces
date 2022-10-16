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

const int INF = 1000000000;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
vector<string> a;
vector<vector<bool> > seen;
vector<vector<int> > d, c;

bool check(int t) {
    queue<pair<int, int> > q;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            c[i][j] = INF;
            if (a[i][j] == 'X' && d[i][j] >= t) {
                c[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x0 = x + dx[i], y0 = y + dy[i];
            if (x0 >= 0 && x0 <= n + 1 && y0 >= 0 && y0 <= m + 1 && c[x0][y0] == INF) {
                c[x0][y0] = c[x][y] + 1;
                q.push({x0, y0});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X' && c[i][j] >= t) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n + 2);
    a[0].resize(m + 2);
    a[n + 1].resize(m + 2);
    for (int i = 0; i <= m + 1; i++) {
        a[0][i] = a[n + 1][i] = '.';
    }
    for (int i = 1; i <= n; i++) {
        a[i].push_back('.');
        string s;
        cin >> s;
        a[i] += s;
        a[i].push_back('.');
    }
    queue<pair<int, int > > q;
    d = vector<vector<int> >(n + 2, vector<int>(m + 2, INF));
    c = vector<vector<int> >(n + 2, vector<int>(m + 2, INF));
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (a[i][j] == '.') {
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x0 = x + dx[i], y0 = y + dy[i];
            if (x0 >= 0 && x0 <= n + 1 && y0 >= 0 && y0 <= m + 1 && d[x0][y0] == INF) {
                d[x0][y0] = d[x][y] + 1;
                q.push({x0, y0});
            }
        }
    }
    seen = vector<vector<bool> > (n + 2, vector<bool>(m + 2, false));
    int left = 1, right = n + m, t = 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (check(middle)) {
            t = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    cout << t - 1 << "\n";
    for (int i = 1; i <= n; i++) {
        string ans;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X' && d[i][j] >= t) {
                ans.push_back('X');
            } else {
                ans.push_back('.');
            }
        }
        cout << ans << "\n";
    }
    //timeDuration();
    return 0;
}