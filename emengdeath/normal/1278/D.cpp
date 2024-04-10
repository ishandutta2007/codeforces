#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e6;
int a[N][2];
int n;
int fa[N];
int x[N], y[N];
vector<int>g[N];
bool bz[N];
vector<pair<int, int> >d;
void ins(int x, int y) {
    while (x < N) {
        g[x].push_back(y);
        x += x & -x;
    }
}
void get(int x, int y) {
    while (x) {
        for (int i = 0; i < g[x].size() && d.size() < n; i ++)
            if (!bz[g[x][i]]) {
                swap(g[x][i], g[x][g[x].size() - 1]);
                g[x].pop_back();
                i --;
            } else {
                d.push_back(make_pair(g[x][i], y));
            }
        x -= x & -x;
    }
}
int getfa(int x) {
    return x == fa[x]? x : fa[x] = getfa(fa[x]);
}
int main(){
    scanf("%d", &n);
    for (int i = 1;i  <= n; i ++){
        scanf("%d %d", &a[i][0], &a[i][1]);
        x[a[i][0]] = i;
        y[a[i][1]] = i;
    }
    for (int i = 1; i <= n + n; i ++)
        if (x[i]) {
            get(a[x[i]][1], x[i]);
            ins(a[x[i]][1], x[i]);
            bz[x[i]] = 1;
        } else {
            bz[y[i]] = 0;
        }
    if (d.size() != n - 1) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; i ++) fa[i]= i ;
    for (auto u:d)
        if (getfa(u.first) == getfa(u.second)) {
            printf("NO\n");
            return 0;
        } else
            fa[getfa(u.first) ]= u.second;
    printf("YES\n");
    return 0;
}