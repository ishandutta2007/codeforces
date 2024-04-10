#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

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

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int dad[1 + MAXN], best[1 + MAXN], depth[1 + MAXN];

void DFS(int node, int father) {
    dad[node] = father;
    depth[node] = depth[father] + 1;
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            best[node] = max(best[node], best[son] + 1);
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), x = Read();
    for (int i = 1; i < n; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    int answer = 0;
    for (int node = x; node != 1; node = dad[node]) {
        if (depth[x] - depth[node] >= depth[node] - 1)
            break;
        answer = max(answer, 2 * (best[node] + depth[node] - 1));
    }
    printf("%d\n", answer);
    return 0;
}