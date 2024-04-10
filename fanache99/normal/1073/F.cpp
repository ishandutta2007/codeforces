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

const int MAXN = 200000;

int branch0 = 0, length0 = 0;
int a1, b1, a2, b2;
vector<int> g[1 + MAXN];
int down1[1 + MAXN], sonDown1[1 + MAXN], down2[1 + MAXN], sonDown2[1 + MAXN];
int up[1 + MAXN], sonUp[1 + MAXN];
int branch[1 + MAXN], length[1 + MAXN], sonBranch1[1 + MAXN], sonBranch2[1 + MAXN], dad[1 + MAXN];

void Down(int node, int father) {
    dad[node] = father;
    for (auto &son : g[node])
        if (son != father) {
            Down(son, node);
            int downNow = down1[son] + 1, sonNow = (sonDown1[son] != 0 ? sonDown1[son] : son);
            if (downNow > down1[node]) {
                down2[node] = down1[node];
                sonDown2[node] = sonDown1[node];
                down1[node] = downNow;
                sonDown1[node] = sonNow;
            }
            else
                if (downNow > down2[node]) {
                    down2[node] = downNow;
                    sonDown2[node] = sonNow;
                }
        }
}

void Up(int node, int father) {
    int best1 = 0, which1 = 0, son1 = 0, best2 = 0, which2 = 0, son2 = 0;
    for (auto &son : g[node])
        if (son != father) {
            int bestNow = down1[son] + 2, sonNow = (sonDown1[son] != 0 ? sonDown1[son] : son);
            if (bestNow > best1) {
                best2 = best1;
                son2 = son1;
                which2 = which1;
                best1 = bestNow;
                son1 = sonNow;
                which1 = son;
            }
            else {
                best2 = bestNow;
                son2 = sonNow;
                which2 = son;
            }
        }
    for (auto &son : g[node])
        if (son != father) {
            up[son] = up[node] + 1;
            sonUp[son] = sonUp[node];
            int bestNow = best1, sonNow = son1;
            if (which1 == son) {
                bestNow = best2;
                sonNow = son2;
            }
            if (bestNow > up[son]) {
                up[son] = bestNow;
                sonUp[son] = sonNow;
            }
            Up(son, node);
        }
}

void DFS(int node, int father) {
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            if (branch[son] && (branch[son] + 1 > branch[node] || (branch[son] + 1 == branch[node] && length[son] > length[node]))) {
                branch[node] = branch[son] + 1;
                length[node] = length[son];
                sonBranch1[node] = sonBranch1[son];
                sonBranch2[node] = sonBranch2[son];
            }
        }
    if (down1[node] && down2[node] && (1 > branch[node] || (1 == branch[node] && down1[node] + down2[node] > length[node]))) {
        branch[node] = 1;
        length[node] = down1[node] + down2[node];
        sonBranch1[node] = sonDown1[node];
        sonBranch2[node] = sonDown2[node];
    }
}

void Solve(int n) {
    for (int node = 1; node <= n; node++) {
        int branch1 = 0, branch2 = 0, length1 = 0, length2 = 0, son11 = 0, son12 = 0, son21 = 0, son22 = 0;
        for (auto &son : g[node])
            if (son != dad[node] && branch[son])
                if (branch[son] > branch1 || (branch[son] == branch1 && length[son] > length1)) {
                    branch2 = branch1;
                    length2 = length1;
                    son21 = son11;
                    son22 = son12;
                    branch1 = branch[son];
                    length1 = length[son];
                    son11 = sonBranch1[son];
                    son12 = sonBranch2[son];
                }
                else
                    if (branch[son] > branch2 || (branch[son] == branch2 && length[son] > length2)) {
                        branch2 = branch[son];
                        length2 = length[son];
                        son21 = sonBranch1[son];
                        son22 = sonBranch2[son];
                    }
        if (branch1 && branch2) {
            if (branch1 + branch2 + 1 > branch0 || (branch1 + branch2 + 1 == branch0 && length1 + length2 > length0)) {
                branch0 = branch1 + branch2 + 1;
                length0 = length1 + length2;
                a1 = son11;
                a2 = son12;
                b1 = son21;
                b2 = son22;
            }
            continue;
        }
        int best1 = 0, son1 = 0, best2 = 0, son2 = 0;
        for (auto &son : g[node])
            if (son != dad[node] && branch[son] == 0) {
                int downNow = down1[son] + 1, sonNow = (sonDown1[son] != 0 ? sonDown1[son] : son);
                if (downNow > best1) {
                    best2 = best1;
                    son2 = son1;
                    best1 = downNow;
                    son1 = sonNow;
                }
                else
                    if (downNow > best2) {
                        best2 = downNow;
                        son2 = sonNow;
                    }
            }
        if (up[node])
            if (up[node] > best1) {
                best2 = best1;
                son2 = son1;
                best1 = up[node];
                son1 = sonUp[node];
            }
            else
                if (up[node] > best2) {
                    best2 = up[node];
                    son2 = sonUp[node];
                }
        if (best1 && best2)
            if (branch1 + 1 > branch0 || (branch1 + 1 == branch0 && length1 + best1 + best2 > length0)) {
                branch0 = branch1 + 1;
                length0 = length1 + best1 + best2;
                a1 = son11;
                a2 = son12;
                b1 = son1;
                b2 = son2;
            }
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i < n; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    Down(1, 0);
    Up(1, 0);
    DFS(1, 0);
    Solve(n);
    printf("%d %d\n%d %d\n", a1, b1, a2, b2);
    return 0;
}