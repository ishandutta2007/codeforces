#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 100000;
const long long INF = 1000000000000000LL;

struct Line {
    long long a, b;
    mutable long double slope;

    Line() {}

    Line(long long _a, long long _b, long double _slope) {
        a = _a;
        b = _b;
        slope = _slope;
    }

    bool operator < (const Line &other) const {
        if (other.b == INF)
            return slope < other.slope;
        if (a != other.a)
            return a > other.a;
        return b < other.b;
    }
};

struct Batch {
    set<Line> lines;

    bool Bad(set<Line>::iterator it) {
        if (next(it) == lines.end() || it == lines.begin())
            return false;
        return (long double) (prev(it)->a - next(it)->a) * (next(it)->b - it->b) <= (long double) (it->a - next(it)->a) * (next(it)->b - prev(it)->b);
    }

    void Compute(set<Line>::iterator it) {
        if (next(it) == lines.end())
            it->slope = INF;
        else
            it->slope = (long double) (it->b - next(it)->b) / (next(it)->a - it->a);
    }

    void Update(Line d) {
        if (lines.find(d) != lines.end())
            return;
        auto it = lines.insert(d).first;
        if (it != lines.begin() && prev(it)->a == it->a) {
            lines.erase(it);
            return;
        }
        if (next(it) != lines.end() && next(it)->a == it->a)
            lines.erase(next(it));
        if (Bad(it)) {
            lines.erase(it);
            return;
        }
        while (it != lines.begin() && Bad(prev(it)))
            lines.erase(prev(it));
        while (next(it) != lines.end() && Bad(next(it)))
            lines.erase(next(it));
        Compute(it);
        if (it != lines.begin())
            Compute(prev(it));
    }

    long long Query(int x) {
        if (lines.empty())
            return INF;
        auto it = lines.lower_bound(Line(0, INF, x));
        return it->a * x + it->b;
    }
};

int a[1 + MAXN], b[1 + MAXN], weight[1 + MAXN], which[1 + MAXN], number = 0;
vector<int> g[1 + MAXN];
long long answer[1 + MAXN];
Batch v[1 + MAXN];

void DFS(int node, int father) {
    weight[node] = 1;
    if (g[node].size() == 1 && father) {
        answer[node] = 0;
        number++;
        which[node] = number;
        v[number].Update({b[node], 0, 0});
        return;
    }
    int bestSon = 0;
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            weight[node] += weight[son];
            if (weight[son] > weight[bestSon])
                bestSon = son;
        }
    which[node] = which[bestSon];
    for (auto &son : g[node])
        if (son != father && son != bestSon) {
            for (auto &it : v[which[son]].lines)
                v[which[node]].Update(it);
            v[which[son]].lines.clear();
        }
    answer[node] = v[which[node]].Query(a[node]);
    v[which[node]].Update({b[node], answer[node], 0});
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        a[i] = Read();
    for (int i = 1; i <= n; i++)
        b[i] = Read();
    for (int i = 1; i < n; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%I64d ", answer[i]);
    return 0;
}