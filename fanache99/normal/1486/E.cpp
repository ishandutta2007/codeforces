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

const long long INF = 1000000000000000000LL;
const int MAXN = 100000;
const int MAXW = 50;

vector<pair<int, int> > g[1 + MAXN];
long long best[1 + MAXN][1 + MAXW];
bool seen[1 + MAXN][1 + MAXW];

struct State {
    long long c;
    int node;
    int w;

    bool operator < (const State &other) const {
        return c > other.c;
    }
};

void dijkstra(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXW; j++) {
            best[i][j] = INF;
        }
    }
    priority_queue<State> h;
    best[1][0] = 0;
    h.push({0, 1, 0});
    while (!h.empty()) {
        int node = h.top().node, w = h.top().w;
        long long c = h.top().c;
        h.pop();
        if (seen[node][w]) {
            continue;
        }
        seen[node][w] = true;
        for (auto it : g[node]) {
            int other = it.first, x = it.second;
            int w0 = (w == 0 ? x : 0), c0 = (w == 0 ? x * x : 2 * w * x + x * x);
            if (c + c0 < best[other][w0]) {
                best[other][w0] = c + c0;
                h.push({c + c0, other, w0});
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    dijkstra(n);
    for (int i = 1; i <= n; i++) {
        if (best[i][0] != INF) {
            cout << best[i][0] << " ";
        } else {
            cout << "-1 ";
        }
    }
    //timeDuration();
    return 0;
}