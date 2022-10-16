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

const int MAXN = 100000;

int wait[1 + MAXN], first[1 + MAXN], last[1 + MAXN], weight[1 + MAXN], number = 0;
bool dependent[1 + MAXN];
vector<int> g[1 + MAXN];

void DFS(int node) {
    number++;
    first[node] = number;
    weight[node] = 1;
    for (auto &son : g[node]) {
        DFS(son);
        weight[node] += weight[son];
    }
    number++;
    last[node] = number;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), k = Read(), q = Read();
    for (int i = 1; i <= k; i++) {
        int a = Read(), b = Read();
        if (wait[b]) {
            g[wait[b]].push_back(a);
            dependent[a] = true;
        }
        wait[b] = a;
    }
    for (int i = 1; i <= n; i++)
        if (!dependent[i])
            DFS(i);
    for (int i = 1; i <= q; i++) {
        int x = Read(), y = Read();
        y = wait[y];
        if (y && first[x] <= first[y] && last[y] <= last[x])
            printf("%d\n", weight[x]);
        else
            printf("0\n");
    }
    return 0;
}