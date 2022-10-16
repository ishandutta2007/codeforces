#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 300000;
const int INF = 2000000000;
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

vector<int> g[1 + MAXN];
int cost[1 + MAXN], answer = INF;
int down[1 + MAXN], up[1 + MAXN];

void Down(int node, int father) {
    down[node] = -INF;
    for (auto &son : g[node])
        if (son != father) {
            Down(son, node);
            down[node] = max(down[node], max(down[son], cost[son]));
        }
}

void Up(int node, int father) {
    int best1 = -INF, son1 = 0, best2 = -INF, son2 = 0;
    for (auto &son : g[node])
        if (son != father)
            if (max(down[son], cost[son]) > best1) {
                best2 = best1;
                son2 = son1;
                best1 = max(down[son], cost[son]);
                son1 = son;
            }
            else
                if (max(down[son], cost[son]) > best2) {
                    best2 = max(down[son], cost[son]);
                    son2 = son;
                }
    for (auto &son : g[node])
        if (son != father) {
            if (son == son1)
                up[son] = max(up[node], max(cost[father], best2));
            else
                up[son] = max(up[node], max(cost[father], best1));
            Up(son, node);
        }
}

void Solve(int node, int father) {
    int current = max(cost[node], cost[father] + 1);
    for (auto &son : g[node])
        if (son != father) {
            current = max(current, max(cost[son] + 1, down[son] + 2));
            Solve(son, node);
        }
    current = max(current, up[node] + 2);
    answer = min(answer, current);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        cost[i] = Read();
    for (int i = 1; i < n; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cost[0] = up[1] = -INF;
    Down(1, 0);
    Up(1, 0);
    Solve(1, 0);
    printf("%d\n", answer);
    return 0;
}