#include <stdio.h>
#include <algorithm>

using namespace std;

struct edge {
    int a,b;
};

int n,m;

edge e[110];
int g[110][110];
int seen[110];
bool ok = true;

void dfs(int v, int c) {
    if (seen[v]) {
        if (seen[v] != c) ok = false;
        return;
    }
    
    seen[v] = c;
    
    for (int i = 0; i < m; i++) {
        if (g[v][i]) {
            if (c == 1) dfs(i, 2);
            else dfs(i, 1);
        }
    }
}

bool inside(int a, int b, int c) {
    return a <= b && b <= c;
}

bool cross(edge e1, edge e2) {
    if (e1.a == e2.a || e1.a == e2.b || e1.b == e2.a || e1.b == e2.b) return false;
    
    if (inside(e1.a, e2.a, e1.b) && !inside(e1.a, e2.b, e1.b)) return true;
    if (inside(e1.a, e2.b, e1.b) && !inside(e1.a, e2.a, e1.b)) return true;
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &e[i].a, &e[i].b);
        if (e[i].a > e[i].b) swap(e[i].a, e[i].b);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = cross(e[i], e[j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (!seen[i]) dfs(i, 1);
    }
    
    if (!ok) printf("Impossible\n");
    else {
        for (int i = 0; i < m; i++) {
            printf("%c", seen[i]==1 ? 'i' : 'o');
        }
        printf("\n");
    }
}