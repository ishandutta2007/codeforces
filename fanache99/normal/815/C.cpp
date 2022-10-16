#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
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

const int MAXN = 5000;
const int INF = 1000000001;

vector<int> g[1 + MAXN];
int n, price[1 + MAXN], discount[1 + MAXN], weight[1 + MAXN];
long long with[1 + MAXN][1 + MAXN], without[1 + MAXN][1 + MAXN];

void DFS(int node) {
    weight[node] = 1;
    with[node][0] = INF;
    for (int i = 2; i <= n; i++)
        with[node][i] = without[node][i] = INF;
    with[node][1] = price[node] - discount[node];
    without[node][1] = price[node];
    if (g[node].empty())
        return;
    for (auto &son : g[node]) {
        DFS(son);
        for (int i = weight[node]; i >= 0; i--)
            for (int j = weight[son]; j >= 0; j--) {
                without[node][i + j] = min(without[node][i + j], without[node][i] + without[son][j]);
                with[node][i + j] = min(with[node][i + j], with[node][i] + with[son][j]);
            }
        weight[node] += weight[son];
    }
    for (int i = 1; i <= n; i++)
        with[node][i] = min(with[node][i], without[node][i]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int limit;
    scanf("%d%d", &n, &limit);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &price[i], &discount[i]);
        if (i > 1) {
            int dad;
            scanf("%d", &dad);
            g[dad].push_back(i);
        }
    }
    DFS(1);
    for (int i = 1; i <= n; i++)
        if (with[1][i] > limit && without[1][i] > limit) {
            printf("%d\n", i - 1);
            return 0;
        }
    printf("%d\n", n);
    return 0;
}