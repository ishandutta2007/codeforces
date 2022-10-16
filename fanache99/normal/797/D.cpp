#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int SIZE = 1 << 17;
const int MAXNODES = 262144;

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
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}


int leftSon[1 + MAXN], rightSon[1 + MAXN], value[1 + MAXN];
pair<int, int> vn[1 + MAXN];
int tree[1 + MAXNODES], seen[1 + MAXN];
bool parent[1 + MAXN], ok[1 + MAXN];

int n, from, to, add, total = 0;

void Update(int node, int left, int right) {
    if (from <= left && right <= to) {
        tree[node] += add;
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle)
        Update(2 * node, left, middle);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right);
}

int where;

int Query(int node, int left, int right, int answer) {
    answer += tree[node];
    if (left == right)
        return answer;
    int middle = (left + right) / 2;
    if (where <= middle)
        return Query(2 * node, left, middle, answer);
    else
        return Query(2 * node + 1, middle + 1, right, answer);
}

void DFS(int node, int depth) {
    where = value[node];
    int howMany = Query(1, 1, n, 0);
    if (howMany == depth)
        ok[value[node]] = true;
    if (leftSon[node] != -1) {
        from = 1;
        to = value[node];
        add = 1;
        Update(1, 1, n);
        DFS(leftSon[node], depth + 1);
        from = 1;
        to = value[node];
        add = -1;
        Update(1, 1, n);
    }
    if (rightSon[node] != -1) {
        from = value[node];
        to = n;
        add = 1;
        Update(1, 1, n);
        DFS(rightSon[node], depth + 1);
        from = value[node];
        to = n;
        add = -1;
        Update(1, 1, n);
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    n = Read();
    for (int i = 1; i <= n; i++) {
        value[i] = Read();
        leftSon[i] = Read();
        rightSon[i] = Read();
        if (leftSon[i] != -1)
            parent[leftSon[i]] = true;
        if (rightSon[i] != -1)
            parent[rightSon[i]] = true;
        vn[i] = make_pair(value[i], i);
    }
    sort(vn + 1, vn + n + 1);
    value[vn[1].second] = 1;
    seen[1]++;
    for (int i = 2; i <= n; i++) {
        value[vn[i].second] = value[vn[i - 1].second];
        if (vn[i].first != vn[i - 1].first)
            value[vn[i].second]++;
        seen[value[vn[i].second]]++;
    }
    from = 1;
    to = n;
    add = 1;
    Update(1, 1, n);
    int root = 0;
    for (int i = 1; i <= n; i++)
        if (!parent[i]) {
            root = i;
            break;
        }
    DFS(root, 1);
    for (int i = 1; i <= value[vn[n].second]; i++)
        if (!ok[i])
            total += seen[i];
    printf("%d\n", total);
    return 0;
}