#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2005;
int n, clist;
bool vis[N];
int a[N];
int b[N];
int f[N], g[N], list[N];
int sf[N][N], sg[N];

template<class T> inline void checkmax(T &a, const T &b)
{if (b > a) a = b;}

struct cmp {
    bool operator()(const int &i, const int &j)
    {return b[i] < b[j] || b[i] == b[j] && a[i] < a[j];}
};

int getf(int x)
{
    if (f[x] > 0) return f[x];
    for (int i = 1; i <= n; ++i) if (i != x && a[x] <= a[i] && b[i] <= b[x])
        getf(i);
    clist = 0;
    for (int i = 1; i <= n; ++i) if (i != x && a[x] <= a[i] && b[i] <= b[x])
        list[++clist] = i;
    memset(g, 0, sizeof(g));
    list[0] = 0;
    sort(list + 1, list + clist + 1, cmp());
    memset(sg, 0, sizeof(sg));
    
    for (int i = 1; i <= clist; ++i) {
        g[i] = g[i - 1];
        sg[i] = -1;
        int lb = 0, rb = i;
        while (lb + 1 < rb) {
            int mid = lb + rb >> 1;
            if (b[list[mid]] <= a[list[i]]) lb = mid; else rb = mid;
        }
        if (g[i] < g[lb] + f[list[i]]) {
            g[i] = g[lb] + f[list[i]];
            sg[i] = lb;
        }
    }
    int t = clist;
    while (t != 0)
        if (sg[t] == -1) --t; else {
            sf[x][++sf[x][0]] = list[t];
            t = sg[t];
        }
    f[x] = g[clist] + 1;
    
    return f[x];
}

void printans(int x)
{
    vis[x] = true;
    for (int i = sf[x][0]; i >= 1; --i) printans(sf[x][i]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = x - y;
        b[i] = x + y;
    }
    ++n;
    a[n] = -2147483647;
    b[n] = 2147483647;
    printf("%d\n", getf(n) - 1);
    printans(n);
    bool first = true;
    for (int i = 1; i < n; ++i) if (vis[i]) {
        if (!first) printf(" ");
        printf("%d", i);
        first = false;
    }
    printf("\n");
}