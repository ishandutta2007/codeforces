#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <vector>
#include <math.h>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>


using namespace std;


const int inf = 1 << 28;
#define maxM 220
struct Node{
    int c, w, pos, next;
}E[10000];
int NE, NV;
int head[maxM], pe[maxM], pv[maxM];
bool vis[maxM];
int cost[maxM];
queue<int> q;


int MCMF(int s, int t, int need) {
    int maxflow = 0, mincost = 0;
    while (true) {
        memset(pv, -1, sizeof(pv));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < NV; i++) {
            cost[i] = inf;
        }
        cost[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].pos;
                if (E[i].c && cost[u] + E[i].w < cost[v]) {
                    cost[v] = cost[u] + E[i].w;
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                    pv[v] = u;  
                    pe[v] = i;
                }
            }
        }
        if (pv[t] == -1) {
            break;
        }
        int aug = inf;
        for(int v = t; v != s; v = pv[v]) {
            aug = min(aug, E[pe[v]].c);
        }
        maxflow += aug;
        mincost += cost[t] * aug;
        for (int v = t; v != s; v = pv[v]) {
            E[pe[v]].c -= aug;
            E[pe[v] ^ 1].c += aug;
        }
    }
    if (maxflow != need) {
        return -1;
    }
    return mincost;
}


void init(){
    memset(head, -1, sizeof(head));
    NE = 0;
}


void insert(int u,int v,int w,int c) {
    E[NE].c = c;    
    E[NE].pos = v;
    E[NE].w = w;    
    E[NE].next = head[u];   
    head[u] = NE++;
    E[NE].c = 0;    
    E[NE].pos = u;
    E[NE].w = -w;  
    E[NE].next = head[v];   
    head[v] = NE++;
}


char dest[210], str[210];
int n;
int cnt[30];


int main() {
    scanf("%s", dest);
    scanf("%d", &n);
    int x;
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        scanf("%d", &x);
        insert(0, i, 0, x);
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; str[j]; j++) {
            cnt[str[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            insert(i, j + 1 + n, i, cnt[j]);
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0; dest[j]; j++) {
        cnt[dest[j] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
        insert(j + 1 + n, n + 27, 0, cnt[j]);
    }
    NV = n + 28;
    printf("%d\n", MCMF(0, n + 27, strlen(dest)));
    return 0;
}