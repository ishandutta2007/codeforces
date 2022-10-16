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

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
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

const int MOD = 998244353;
const int MAXN = 200000;
const int MAXK = 30;
const int INF = 1000000000;

vector<int> g[2][1 + MAXN];
int d[2][1 + MAXN][1 + MAXK];

struct State {
    int p;
    int node;
    int t;
};

void small(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXK; j++) {
            d[0][i][j] = d[1][i][j] = INF;
        }
    }
    deque<State> q;
    q.push_back({0, 1, 0});
    d[0][1][0] = 0;
    while (!q.empty()) {
        State st = q.front();
        q.pop_front();
        int p = st.p, node = st.node, t = st.t;
        if (t < MAXK && d[p ^ 1][node][t + 1] == INF) {
            d[p ^ 1][node][t + 1] = d[p][node][t];
            q.push_front({p ^ 1, node, t + 1});
        }
        for (auto it : g[p][node]) {
            if (d[p][it][t] == INF) {
                d[p][it][t] = d[p][node][t] + 1;
                q.push_back({p, it, t});
            }
        }
    }
    int answer = 2 * INF;
    for (int t = 0; t <= MAXK; t++) {
        for (int p = 0; p < 2; p++) {
            if (d[p][n][t] != INF) {
                answer = min(answer, d[p][n][t] + (1 << t) - 1);
            }
        }
    }
    if (answer != 2 * INF) {
        cout << answer % MOD << "\n";
        exit(0);
    }
}

pair<int, int> best[2][1 + MAXN];

struct Node {
    int p;
    int node;
    int c1;
    int c2;

    bool operator < (const Node &other) const {
        return make_pair(c1, c2) > make_pair(other.c1, other.c2);
    }
};

void large(int n) {
    priority_queue<Node> h;
    for (int i = 1; i <= n; i++) {
        best[0][i] = best[1][i] = make_pair(INF, INF);
    }
    best[0][1] = make_pair(0, 0);
    h.push({0, 1, 0, 0});
    while (!h.empty()) {
        Node st = h.top();
        h.pop();
        int p = st.p, node = st.node, c1 = st.c1, c2 = st.c2;
        if (best[p][node] != make_pair(c1, c2)) {
            continue;
        }
        if (make_pair(c1 + 1, c2) < best[p ^ 1][node]) {
            best[p ^ 1][node] = make_pair(c1 + 1, c2);
            h.push({p ^ 1, node, c1 + 1, c2});
        }
        for (auto it : g[p][node]) {
            if (make_pair(c1, c2 + 1) < best[p][it]) {
                best[p][it] = make_pair(c1, c2 + 1);
                h.push({p, it, c1, c2 + 1});
            }
        }
    }
    pair<int, int> dist = min(best[0][n], best[1][n]);
    int answer = 1;
    for (int i = 1; i <= dist.first; i++) {
        answer *= 2;
        if (answer >= MOD) {
            answer -= MOD;
        }
    }
    answer += dist.second - 1;
    if (answer >= MOD) {
        answer -= MOD;
    }
    cout << answer << "\n";
}

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[0][a].push_back(b);
        g[1][b].push_back(a);
    }
    small(n);
    large(n);
    return 0;
}