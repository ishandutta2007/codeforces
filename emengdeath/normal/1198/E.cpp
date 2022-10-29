#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e6;
const int MAXN = 1e9;
int n,m,s,t,ss,tt,ans,flow;
int g[N],a[N][3],help[4][2],vh[N],dis[N],di[N],pre[N],his[N];
char map[100][100];
void ins(int x,int y,int z){
    static int sum = 1;
    a[++sum][0]=y,a[sum][1]=z,a[sum][2]=g[x],g[x]=sum;
    a[++sum][0]=x,a[sum][1]=0,a[sum][2]=g[y],g[y]=sum;
}
void clear(){
    for (int i=0;i<N;i++)
        vh[i]=dis[i]=0;
}
void sap(int s,int t){
    static int x,argue,mn,k;
    static bool p;
    clear();
    flow=0;
    argue=MAXN,x=s;
    vh[0]=t+1;
    while (dis[s]<=t+1){
        p=0;
        his[x]=argue;
        for (int i=di[x];i;i=a[i][2])
            if (a[i][1]&&dis[x]==dis[a[i][0]]+1){
                p=1,argue=min(argue,a[i][1]),di[x]=i,pre[a[i][0]]=x;
                x=a[i][0];
                if (x==t){
                    flow+=argue;
                    while (x!=s){
                        x=pre[x];
                        a[di[x]][1]-=argue;
                        a[di[x]^1][1]+=argue;
                    }
                    argue=MAXN;
                }
                break;
            }
        if (!p){
            if (!(--vh[dis[x]]))break;
            mn=t+2;
            for (int i=g[x];i;i=a[i][2])
                if (a[i][1]&&dis[a[i][0]]<mn)
                    mn=dis[a[i][0]],k=i;
            ++vh[dis[x]=++mn];
            di[x]=k;
            if (x!=s)
                x=pre[x],argue=his[x];
        }
    }
}
struct node{
    int x, y, xx, yy;
    bool xinclude(int l, int r) {
        return x <= l &&  r <= xx;
    }
    bool yinclude(int l, int r) {
        return y <= l &&  r <= yy;
    }
}e[N];
int x[N], y[N];
int bzx[N], bzy[N];
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i ++) {
        scanf("%d %d %d %d", &e[i].x, &e[i].y, &e[i].xx, &e[i].yy);
        e[i].x--;
        e[i].y--;
        x[++x[0]] = e[i].x;
        x[++x[0]] = e[i].xx;
        y[++y[0]] = e[i].y;
        y[++y[0]] = e[i].yy;
    }
    sort(x + 1, x + x[0] + 1);
    sort(y + 1, y + y[0] + 1);
    x[0] = 1;
    for (int i = 1; i <= m + m; i ++)
        if (x[x[0]] != x[i]) x[++x[0]] = x[i];
    y[0] = 1;
    for (int i = 1; i <= m + m; i ++)
        if (y[y[0]] != y[i]) y[++y[0]] = y[i];
    int tot =  0;
    int ans = 0;
    for (int i = 1; i < x[0] ; i ++)
        for (int j = 1; j <= m ; j ++)
            if (e[j].xinclude(x[i], x[i + 1])) {
                bzx[i] = ++ tot;
                ans += x[i + 1] - x[i];
                ins(0, tot, x[i + 1] - x[i]);
                break;
            }
    for (int i = 1; i < y[0] ; i ++)
        for (int j = 1; j <= m ; j ++)
            if (e[j].yinclude(y[i], y[i + 1])) {
                bzy[i] = ++ tot;
                ans += y[i + 1] - y[i];
                break;
            }
    ++tot;
    for (int i= 1; i < y[0]; i ++)
        if (bzy[i]) {
            ins(bzy[i], tot, y[i + 1] - y[i]);
        }
    for (int i = 1; i < x[0]; i ++)
        if (bzx[i])
            for (int j = 1; j < y[0]; j ++)
                if (bzy[j]) {
                    for (int k = 1; k <= m; k ++)
                        if (e[k].yinclude(y[j], y[j + 1]) && e[k].xinclude(x[i], x[i + 1])) {
                            ins(bzx[i], bzy[j], MAXN);
                            break;
                        }
                }
    sap(0, tot);
    printf("%d\n", flow);
    return 0;
}