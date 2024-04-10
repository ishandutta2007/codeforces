#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

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

const int MAXN = 1000;

bool edge[1 + MAXN][1 + MAXN];
int d[2][1 + MAXN];
vector<int> g[1 + MAXN];

void BFS(int start, int best[], int n) {
    queue<int> Queue;
    Queue.push(start);
    for (int i = 1; i <= n; i++)
        best[i] = -1;
    best[start] = 0;
    Queue.push(start);
    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        for (auto &it : g[node])
            if (best[it] == -1) {
                best[it] = best[node] + 1;
                Queue.push(it);
            }
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        edge[a][b] = edge[b][a] = true;
    }
    BFS(s, d[0], n);
    BFS(t, d[1], n);
    int answer = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (!edge[i][j] && d[0][i] + 1 + d[1][j] >= d[0][t] && d[1][i] + 1 + d[0][j] >= d[0][t])
                answer++;
    printf("%d\n", answer);
    return 0;
}