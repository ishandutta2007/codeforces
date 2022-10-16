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

const int MAXN = 200000;
const int MAXM = 200000;
const int MAXQ = 200000;
const int MAXLOG = 18;

int p[1 + MAXN], v[1 + MAXM], where[1 + MAXN];
int go[1 + MAXM + 1][1 + MAXLOG], last[1 + MAXN], finish[1 + MAXM];
char answer[1 + MAXQ + 1];
vector<pair<int, int> > queries[1 + MAXM];
int st[1 + MAXM];

int main() {
    timeBegin();
    InputReader cin;
    //ofstream fout("input.in");
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    if (n == 1) {
        for (int i = 1; i <= q; i++) {
            answer[i] = '1';
        }
    } else {
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            where[p[i]] = i;
            last[i] = m + 1;
        }
        for (int i = 1; i <= m; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < MAXLOG; i++) {
            go[m + 1][i] = m + 1;
        }
        finish[m + 1] = m + 1;
        for (int i = m; i >= 1; i--) {
            go[i][0] = last[p[where[v[i]] % n + 1]];
            for (int j = 1; j < MAXLOG; j++) {
                go[i][j] = go[go[i][j - 1]][j - 1];
            }
            finish[i] = i;
            for (int j = 0; j < MAXLOG; j++) {
                if (((n - 1) >> j) & 1) {
                    finish[i] = go[finish[i]][j];
                }
            }
            last[v[i]] = i;
        }
        for (int i = 1; i <= q; i++) {
            int a, b;
            cin >> a >> b;
            queries[b].push_back({a, i});
        }
        for (int i = 1, top = 0; i <= m; i++) {
            while (top > 0 && finish[st[top]] >= finish[i]) {
                top--;
            }
            top++;
            st[top] = i;
            for (auto it : queries[i]) {
                int limit = it.first, id = it.second;
                int left = 1, right = top, best = top;
                while (left <= right) {
                    int middle = (left + right) / 2;
                    if (st[middle] >= limit) {
                        best = middle;
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                }
                answer[id] = '0' + (finish[st[best]] <= i);
            }
        }
    }
    answer[q + 1] = 0;
    cout << (answer + 1) << "\n";
    //timeDuration();
    return 0;
}