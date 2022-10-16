#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

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

const int MAXN = 100000;
const int MAXQ = 200000;
const int MAXNODES = 262144;

struct Point {
    int x;
    int y;

    bool operator < (const Point &other) const {
        return x < other.x;
    }
};

Point v[1 + MAXQ];

struct Query {
    Point a;
    Point b;
    int index;

    bool operator < (const Query &other) const {
        return b < other.b;
    };
};

Query query[1 + MAXQ];
bool ok[1 + MAXQ];
int tree[1 + MAXNODES], where, from, to, change;

void Update(int node, int left, int right) {
    if (left == right) {
        tree[node] = change;
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle);
    else
        Update(2 * node + 1, middle + 1, right);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int Query(int node, int left, int right) {
    if (from <= left && right <= to)
        return tree[node];
    int answer = MAXN, middle = (left + right) / 2;
    if (from <= middle)
        answer = min(answer, Query(2 * node, left, middle));
    if (middle + 1 <= to)
        answer = min(answer, Query(2 * node + 1, middle + 1, right));
    return answer;
}

void Solve(int k, int q, int n, int m) {
    sort(v + 1, v + k + 1);
    sort(query + 1, query + q + 1);
    for (int i = 1, j = 1; i <= q; i++) {
        while (j <= k && v[j].x <= query[i].b.x) {
            where = v[j].y;
            change = v[j].x;
            Update(1, 1, m);
            j++;
        }
        from = query[i].a.y;
        to = query[i].b.y;
        if (Query(1, 1, m) >= query[i].a.x)
            ok[query[i].index] = true;
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), k = Read(), q = Read();
    for (int i = 1; i <= k; i++) {
        v[i].x = Read();
        v[i].y = Read();
    }
    for (int i = 1; i <= q; i++) {
        query[i].a.x = Read();
        query[i].a.y = Read();
        query[i].b.x = Read();
        query[i].b.y = Read();
        query[i].index = i;
    }
    Solve(k, q, n, m);
    for (int i = 1; i <= k; i++)
        swap(v[i].x, v[i].y);
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= q; i++) {
        swap(query[i].a.x, query[i].a.y);
        swap(query[i].b.x, query[i].b.y);
    }
    Solve(k, q, m, n);
    for (int i = 1; i <= q; i++)
        if (ok[i])
            printf("YES\n");
        else
            printf("NO\n");
    return 0;
}