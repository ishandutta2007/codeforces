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
const int MAXNODES = 524288;
const int MAXVAL = 100;

char go[1 + 4 * MAXN][1 + MAXVAL];
int v[1 + MAXN];

struct Event {
    int where;
    int id;
    int x;
    int y;
    int type;

    bool operator < (const Event &other) const {
        return where < other.where;
    }
};

Event update[1 + 2 * MAXN];

void Update(int node, int left, int right, int where, int type, int x, int y) {
    if (left == right) {
        if (type)
            go[node][x] = y;
        else
            go[node][x] = x;
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle, where, type, x, y);
    else
        Update(2 * node + 1, middle + 1, right, where, type, x, y);
    for (int i = 1; i <= MAXVAL; i++)
        go[node][i] = go[2 * node + 1][go[2 * node][i]];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    int m = Read();
    for (int i = 1; i <= 4 * m; i++)
        for (int j = 1; j <= MAXVAL; j++)
            go[i][j] = j;
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read(), x = Read(), y = Read();
        update[2 * i - 1] = {a, i, x, y, 1};
        update[2 * i] = {b + 1, i, x, y, 0};
    }
    sort(update + 1, update + 2 * m + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= 2 * m && update[j].where == i) {
            Update(1, 1, m, update[j].id, update[j].type, update[j].x, update[j].y);
            j++;
        }
        printf("%d ", go[1][v[i]]);
    }
    return 0;
}