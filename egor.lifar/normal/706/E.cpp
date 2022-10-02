#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <bitset>


using namespace std;


#define next next1
const int N = 1010;
int dir[][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
struct node{
    int v;
    int next[4];
    node(){
        for(int i = 0; i < 4; i++) {
            next[i] = -1;
        }
    }
}nodes[N * N];
int n, m;


int id(int x, int y) {
    return x * m + y;
}


int getid(int a, int b, int rt) {
    for(int i = 0; i < b; i++) {
        rt = nodes[rt].next[3];
    }
    for(int i = 0; i < a; i++)  {
        rt = nodes[rt].next[2];
    }
    return rt;
}


int rt = 0;
int ans[N][N];
int q;


int swapnext(int u, int v, int k) {
    int ou = nodes[u].next[k], ov = nodes[v].next[k];
    nodes[u].next[k] = ov;
    nodes[v].next[k] = ou;
    if (ou != -1) {
        nodes[ou].next[k ^ 2] = v;
    }
    if (ov != -1) {
        nodes[ov].next[k ^ 2] = u;
    }
}


int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nodes[i * m + j] = node();
            scanf("%d", &nodes[i * m + j].v);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = id(i, j);
            for(int k = 0; k < 4; k++) {
                int cx = i + dir[k][0];
                int cy = j + dir[k][1];
                if (!(cx >= 0 && cx < n && cy >= 0 && cy < m)) {
                    continue;
                }
                int v = id(cx, cy);
                nodes[u].next[k] = v;
                nodes[v].next[k ^ 2] = u;
            }
        }
    }
    for (int ii = 0; ii < q; ii++) {
        int a, b, c, d, h, w;
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);
        a--;b--;c--;d--;
        int a1 = getid(a, b, rt), c1 = getid(c, d, rt);
        int a2, b1, b2, c2, d1, d2;
        if (w > 1) {
            b1 = nodes[a1].next[3], d1 = nodes[c1].next[3];
            for(int i = 0; i < w - 2; i++) {
                swapnext(b1, d1, 0);
                b1 = nodes[b1].next[3];
                d1 = nodes[d1].next[3];
            }
        } else {
            b1 = a1;
            d1 = c1;
        }
        if (h > 1) {
            b2 = nodes[b1].next[2], d2 = nodes[d1].next[2];
            for(int i = 0; i < h - 2; i++) {
                swapnext(b2, d2, 3);
                b2 = nodes[b2].next[2], d2 = nodes[d2].next[2];
            }
        } else {
            b2 = b1;
            d2 = d1;
        }
        if (w > 1) {
            a2 = nodes[b2].next[1], c2 = nodes[d2].next[1];
            for(int i = 0; i < w - 2; i++) {
                swapnext(a2, c2, 2);
                a2 = nodes[a2].next[1];
                c2 = nodes[c2].next[1];
            }
        } else {
            a2 = b2;
            c2 = d2;
        } 
        if (h > 1) {
            a1 = nodes[a2].next[0], c1 = nodes[c2].next[0];
            for(int i = 0; i < h - 2; i++) {
                swapnext(a1, c1, 1);
                a1 = nodes[a1].next[0];
                c1 = nodes[c1].next[0];
            }
        } else {
            a1 = a2, c1 = c2;
        }
        swapnext(a1, c1, 0);
        swapnext(a2, c2, 2);
        if (w > 1) {
            swapnext(b1, d1, 0);
            swapnext(b2, d2, 2);
        }
        swapnext(a1, c1, 1);
        swapnext(b1, d1, 3);
        if (h > 1) {
            swapnext(a2, c2, 1);
            swapnext(b2, d2, 3);
        }
        if(a == 0 && b == 0) {
            rt = c1;
        }
        if (c == 0 && d == 0) {
            rt = a1;
        }
    }
    ans[0][0] = rt;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            ans[i][0] = nodes[ans[i - 1][0]].next[2];
        }
        printf("%d ", nodes[ans[i][0]].v);
        for(int j = 1; j < m; j++) {
            ans[i][j] = nodes[ans[i][j - 1]].next[3];
            printf("%d ", nodes[ans[i][j]].v);
        }
        printf("\n");
    }
    return 0;
}