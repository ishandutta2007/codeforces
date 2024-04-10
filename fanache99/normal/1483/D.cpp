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

const int MAXN = 600;
const int MAXM = MAXN * (MAXN - 1) / 2;
const int MAXQ = MAXN * (MAXN - 1);
const long long INF = 1000000000000000000LL;

struct Edge {
    int a;
    int b;
    long long w;
};
Edge e[1 + MAXM];
long long d[1 + MAXN][1 + MAXN];
struct Triple {
    int u;
    int v;
    long long l;
};
Triple t[1 + MAXQ];
long long best[1 + MAXN][1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].w;
        d[e[i].a][e[i].b] = d[e[i].b][e[i].a] = e[i].w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> t[i].u >> t[i].v >> t[i].l;
        t[i + q] = t[i];
        swap(t[i].u, t[i].v);
    }
    q *= 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            best[i][j] = -INF;
        }
        for (int j = 1; j <= q; j++) {
            best[i][t[j].u] = max(best[i][t[j].u], t[j].l - d[i][t[j].v]);
        }
    }
    int answer = 0;
    for (int i = 1; i <= m; i++) {
        bool found = false;
        for (int j = 1; j <= n; j++) {
            long long limit = e[i].w + d[j][e[i].a];
            if (limit <= best[e[i].b][j]) {
                found = true;
                break;
            }
        }
        if (found) {
            answer++;
        }
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}