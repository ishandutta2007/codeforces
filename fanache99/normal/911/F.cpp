//#include <iostream>
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

const int MAXN = 200000;

vector<int> g[1 + MAXN];
vector<pair<int, int> > nodes;
int dad[1 + MAXN], depth[1 + MAXN];
int v[1 + MAXN + 1];
int m = 0, where;
long long answer = 0;

void DFS(int node, int father) {
    dad[node] = father;
    depth[node] = depth[father] + 1;
    for (auto &son : g[node])
        if (son != father)
            DFS(son, node);
}

void Solve(int node, int father) {
    depth[node] = depth[father] + 1;
    for (auto &son : g[node])
        if (son != father)
            Solve(son, node);
    if (where - 1 > m - where) {
        answer += where - 1 + depth[node];
        nodes.push_back(make_pair(node, v[1]));
    }
    else {
        answer += m - where + depth[node];
        nodes.push_back(make_pair(node, v[m]));
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    int first = 0, second = 0;
    for (int i = 1; i <= n; i++)
        if (depth[i] > depth[first])
            first = i;
    DFS(first, 0);
    for (int i = 1; i <= n; i++)
        if (depth[i] > depth[second])
            second = i;
    for (int node = second; node; node = dad[node]) {
        m++;
        v[m] = node;
    }
    for (int i = 1; i <= m; i++) {
        where = i;
        depth[v[i]] = 0;
        for (auto &son : g[v[i]])
            if (son != v[i - 1] && son != v[i + 1])
                Solve(son, v[i]);
    }
    for (int i = m; i >= 2; i--) {
        answer += i - 1;
        nodes.push_back(make_pair(v[i], v[1]));
    }
    printf("%I64d\n", answer);
    for (auto &it : nodes)
        printf("%d %d %d\n", it.first, it.second, it.first);
    return 0;
}