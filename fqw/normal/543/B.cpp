#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

const int MAXN=3010;

VI es[MAXN];
int n, m;
int cores[4], len1, len2;

int dis[MAXN][MAXN];

int main() {
    scanf("%d%d", &n,&m);
    forint(i, 1, n) es[i].clear();
    forint(i, 1, m) {
        int a, b;
        scanf("%d%d", &a,&b);
        es[a].PB(b), es[b].PB(a);
    }
    scanf("%d%d%d",  &cores[0],&cores[1],&len1);
    scanf("%d%d%d",  &cores[2],&cores[3],&len2);

    forint(x0, 1, n) {
        static bool vis[MAXN];
        queue<int> que;

        fillchar(vis, false);
        fillchar(dis[x0], 50);
        dis[x0][x0]=0; 
        vis[x0]=true;
        que.push(x0);
        while(!que.empty()) {
            int x=que.front();
            que.pop();
            for(int y: es[x])
                if(!vis[y]) {
                    vis[y]=true;
                    dis[x0][y]=dis[x0][x]+1;
                    que.push(y);
                }
        }
    }
    if(dis[cores[0]][cores[1]]>len1 || dis[cores[2]][cores[3]]>len2)
        printf("-1\n");
    else {
        int ans=dis[cores[0]][cores[1]]+dis[cores[2]][cores[3]];
        int a1=cores[0], b1=cores[1];
        int a2=cores[2], b2=cores[3];
        forint(x, 1, n) forint(y, 1, n) {
            int d=dis[x][y];
            int z1=min(dis[a1][x]+dis[b1][y], dis[a1][y]+dis[b1][x]);
            int z2=min(dis[a2][x]+dis[b2][y], dis[a2][y]+dis[b2][x]);
            if(z1+d>len1) continue;
            if(z2+d>len2) continue;
            setmin(ans, d+z1+z2);
        }
        printf("%d\n", m-ans);
    }

    return 0;
}