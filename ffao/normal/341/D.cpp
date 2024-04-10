#include <iostream>
#include <stdio.h>

using namespace std;

int n,m,x1,y1,x2,y2;
int op, val;
int multree[1010][1010][2];
int addtree[1010][1010][2];

int query2(int tree[1010][1010][2], int x, int y) {
    int mul = 0, add = 0;
    for (int j = y; j > 0; j -= j&-j) {
        mul ^= tree[x][j][0];
        add ^= tree[x][j][1];
    }

    return (mul * (y%2)) ^ add;
}

int query1(int x, int y) {
    int mul = 0, add = 0;

    for (int i = x; i > 0; i -= i&-i) {
        mul ^= query2(multree, i, y);
        add ^= query2(addtree, i, y);
    }

    return (mul * (x%2)) ^ add;
}


int query(int x1, int x2, int y1, int y2) {
    return query1(x2, y2) ^ query1(x1-1, y2) ^ query1(x2, y1-1) ^ query1(x1-1, y1-1);
}

int ev(int x) { return x%2; }

void update2(int tree[1010][1010][2], int x, int y, int mul, int add) {
    for (int i = x; i <= n; i += i&-i) {
        for (int j = y; j <= n; j += j&-j) {
            tree[i][j][0] ^= mul;
            tree[i][j][1] ^= add;
        }
    }
}

void update1(int x, int y1, int y2, int mul, int add) {
    update2(multree, x, y1, mul, mul * ev(y1 - 1));
    update2(multree, x, y2, mul, mul * ev(y2));

    update2(addtree, x, y1, add, add * ev(y1 - 1));
    update2(addtree, x, y2, add, add * ev(y2));
}

void update(int x1, int x2, int y1, int y2, int by) {
    update1(x1, y1, y2, by, by * ev(x1 - 1));
    update1(x2, y1, y2, by, by * ev(x2));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &op, &x1, &y1, &x2, &y2);
        if (op == 2) {
            scanf("%d", &val);
            update(x1,x2,y1,y2,val);
        }
        else {
            printf("%d\n", query(x1,x2,y1,y2));
        }
    }
}