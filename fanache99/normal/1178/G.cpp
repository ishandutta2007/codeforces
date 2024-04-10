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
const int MAXSQRT = 200000;

vector<int> g[1 + MAXN];
vector<int> bucket[MAXSQRT];
int a[1 + MAXN], b[1 + MAXN];
int first[1 + MAXN], last[1 + MAXN], id;
int v[MAXN];
long long aSum[1 + MAXN], bSum[1 + MAXN], x[MAXSQRT];
int p[MAXSQRT];

long long myAbs(long long x) {
    return (x < 0 ? -x : x);
}

void DFS(int node) {
    v[id] = node;
    first[node] = id++;
    aSum[node] += a[node];
    bSum[node] += b[node];
    for (auto son : g[node]) {
        aSum[son] = aSum[node];
        bSum[son] = bSum[node];
        DFS(son);
    }
    bSum[node] = myAbs(bSum[node]);
    last[node] = id - 1;
}

inline bool compareSlope(const int &a, const int &b) {
    return bSum[a] < bSum[b];
}

struct Line {
    long long a;
    long long b;

    long long evaluate(long long x) {
        return a * x + b;
    }
};

vector<Line> st[MAXSQRT];

long double intersect(Line p, Line q) {
    return (long double) (q.b - p.b) / (p.a - q.a);
}

void addLine(Line l, int id) {
    if (l.a == 0) {
        return;
    }
    if (!st[id].empty() && st[id].back().a == l.a) {
        l.b = max(st[id].back().b, l.b);
        st[id].pop_back();
    }
    while (st[id].size() >= 2 && intersect(l, st[id].back()) <= intersect(st[id].back(), st[id][st[id].size() - 2])) {
        st[id].pop_back();
    }
    st[id].push_back(l);
}

void addLines(int id, int sign) {
    reverse(bucket[id].begin(), bucket[id].end());
    for (auto it : bucket[id]) {
        Line l = {bSum[it] * sign, bSum[it] * aSum[it] * sign};
        addLine(l, id);
    }
}

void shift(int id, int val) {
    x[id] += val;
    while (p[id] + 1 < st[id].size() && intersect(st[id][p[id]], st[id][p[id] + 1]) <= x[id]) {
        p[id]++;
    }
}

void redoHull(int id) {
    for (auto it : bucket[id]) {
        aSum[it] += x[id];
    }
    x[id] = 0;
    st[id].clear();
    addLines(id, -1);
    addLines(id, 1);
    p[id] = 0;
    shift(id, 0);
}

long long getBest(int id) {
    shift(id, 0);
    if (st[id].empty()) {
        return 0;
    } else {
        return st[id][p[id]].evaluate(x[id]);
    }
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("abbreviation.out");
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    DFS(1);
    int len = sqrt(n / 6) + 1;
    for (int b = 0; b * len < n; b++) {
        int i = b * len, j = min(n - 1, (b + 1) * len - 1);
        for (int k = i; k <= j; k++) {
            bucket[b].push_back(v[k]);
        }
        sort(bucket[b].begin(), bucket[b].end(), compareSlope);
        redoHull(b);
    }
    for (int t = 1; t <= q; t++) {
        int type;
        cin >> type;
        if (type == 1) {
            int node, val;
            cin >> node >> val;
            int l = first[node], r = last[node];
            for (int b = l / len; b <= r / len; b++) {
                int i = b * len, j = min(n - 1, (b + 1) * len - 1);
                if (l <= i && j <= r) {
                    shift(b, val);
                } else {
                    for (int k = max(l, i); k <= min(r, j); k++) {
                        aSum[v[k]] += val;
                    }
                    redoHull(b);
                }
            }
        } else {
            int node;
            cin >> node;
            int l = first[node], r = last[node];
            long long answer = 0;
            for (int b = l / len; b <= r / len; b++) {
                int i = b * len, j = min(n - 1, (b + 1) * len - 1);
                if (l <= i && j <= r) {
                    answer = max(answer, getBest(b));
                } else {
                    for (int k = max(l, i); k <= min(r, j); k++) {
                        answer = max(answer, myAbs(aSum[v[k]] + x[b]) * bSum[v[k]]);
                    }
                }
            }
            cout << answer << "\n";
        }
    }
    //timeDuration();
    return 0;
}