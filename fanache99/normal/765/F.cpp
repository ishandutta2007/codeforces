#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 100000;
const int MAXM = 300000;
const int SIZE = 1 << 17;
const int MAXLOG = 16;
const int INF = 1000000000;

char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

pair<int, int> value[1 + MAXN];
int normal[1 + MAXN], tree[1 + 4 * MAXN];
vector<pair<int, int> > bigger[1 + MAXN], smaller[1 + MAXN];

void TreeUpdate(int n, int where, int change) {
    int node = 1, left = 1, right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        if (where <= middle) {
            node *= 2;
            right = middle;
        }
        else {
            node = 2 * node + 1;
            left = middle + 1;
        }
    }
    tree[node] = max(tree[node], change);
    node /= 2;
    while (node) {
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        node /= 2;
    }
}

int from, to;

int TreeQuery(int node, int left, int right) {
    if (from <= left && right <= to)
        return tree[node];
    int middle = (left + right) / 2, answer = -INF;
    if (from <= middle)
        answer = TreeQuery(2 * node, left, middle);
    if (middle + 1 <= to)
        answer = max(answer, TreeQuery(2 * node + 1, middle + 1, right));
    return answer;
}

void Precompute(int n) {
    sort(value + 1, value + n + 1);
    for (int i = 1; i <= n; i++)
        normal[-value[i].second] = i;
    for (int i = 1; i <= n; i++) {
        from = normal[i];
        to = n;
        while (from < to) {
            int where = TreeQuery(1, 1, n);
            if (where < 1)
                break;
            int delta = (value[normal[where]].first - value[normal[i]].first);
            int left = from, right = normal[where] - 1, answer = from;
            bigger[i].push_back(make_pair(where, delta));
            delta /= 2;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (value[normal[i]].first + delta >= value[middle].first) {
                    answer = middle;
                    left = middle + 1;
                }
                else
                    right = middle - 1;
            }
            to = answer;
        }
        TreeUpdate(n, normal[i], i);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++)
        value[i].second *= -1;
    sort(value + 1, value + n + 1);
    for (int i = 1; i <= n; i++)
        normal[value[i].second] = i;
    for (int i = 1; i <= n; i++) {
        from = 1;
        to = normal[i];
        while (from < to) {
            int where = TreeQuery(1, 1, n);
            if (where < 1)
                break;
            int delta = (value[normal[i]].first - value[normal[where]].first);
            int left = normal[where] + 1, right = to, answer = to;
            smaller[i].push_back(make_pair(where, delta));
            delta /= 2;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (value[normal[i]].first - delta <= value[middle].first) {
                    answer = middle;
                    right = middle - 1;
                }
                else
                    left = middle + 1;
            }
            from = answer;
        }
        TreeUpdate(n, normal[i], i);
    }
}

struct Query {
    int from;
    int to;
    int index;
    int answer;
};

Query queries[1 + MAXM];

inline bool CompareRight(const Query &a, const Query &b) {
    return a.to < b.to;
}

inline bool CompareIndex(const Query &a, const Query &b) {
    return a.index < b.index;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++) {
        value[i].first = Read();
        value[i].second = -i;
    }
    Precompute(n);
    int m = Read();
    for (int i = 1; i <= m; i++) {
        queries[i].from = Read();
        queries[i].to = Read();
        queries[i].index = i;
    }
    sort(queries + 1, queries + m + 1, CompareRight);
    int pointer = 1;
    for (int i = 1; i <= 4 * n; i++)
        tree[i] = -INF;
    for (int i = 1; i <= m; i++) {
        while (pointer <= queries[i].to) {
            for (auto &it : bigger[pointer])
                TreeUpdate(n, it.first, -it.second);
            for (auto &it : smaller[pointer])
                TreeUpdate(n, it.first, -it.second);
            pointer++;
        }
        from = queries[i].from;
        to = queries[i].to;
        queries[i].answer = -TreeQuery(1, 1, n);
    }
    from = 1;
    to = 1;
    sort(queries + 1, queries + m + 1, CompareIndex);
    for (int i = 1; i <= m; i++)
        printf("%d\n", queries[i].answer);
    return 0;
}