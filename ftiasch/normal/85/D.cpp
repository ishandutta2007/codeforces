// Yandex Algorithm 2011 Round 1
// Problem D -- Sum of Medians
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 111111;

int nodeCnt, root, key[N], priority[N], childs[N][2], size[N];
long long sum[N][5];

void update(int &x) {
    size[x] = size[childs[x][0]] + 1 + size[childs[x][1]];
    for (int i = 0; i < 5; ++ i) {
        sum[x][i] = sum[childs[x][0]][i];
    }
    sum[x][(size[childs[x][0]] + 1) % 5] += key[x];
    for (int i = 0; i < 5; ++ i) {
        sum[x][(size[childs[x][0]] + 1 + i) % 5] += sum[childs[x][1]][i];
    }
}

void rotate(int &x, int t) {
    int y = childs[x][t];
    childs[x][t] = childs[y][1 - t];
    childs[y][1 - t] = x;
    update(x);
    update(y);
    x = y;
}

void insert(int &x, int v) {
    if (x) {
        int t = key[x] < v;
        insert(childs[x][t], v);
        if (priority[childs[x][t]] < priority[x]) {
            rotate(x, t);
        }
    } else {
        x = nodeCnt ++;
        key[x] = v;
        priority[x] = rand();
        childs[x][0] = childs[x][1] = 0;
    }
    update(x);
}

void erase(int &x, int v) {
    if (key[x] == v) {
        if (childs[x][0] == 0 and childs[x][1] == 0) {
            x = 0;
            return;
        }
        rotate(x, priority[childs[x][0]] > priority[childs[x][1]]);
        erase(x, v);
    } else {
        erase(childs[x][key[x] < v], v);
    }
    update(x);
}

int main() {
    size[0] = 0;
    for (int i = 0; i < 5; ++ i) {
        sum[0][i] = 0;
    }
    priority[0] = INT_MAX;
    nodeCnt = 1;
    int n;
    scanf("%d", &n);
    int root = 0;
    while (n --) {
        char op[22];
        int x;
        scanf("%s", op);
        if (op[0] != 's') {
            scanf("%d", &x);
            if (op[0] == 'a') {
                insert(root, x);
            } else {
                erase(root, x);
            }
        } else {
            cout << sum[root][3] << endl;
        }
    }
    return 0;
}