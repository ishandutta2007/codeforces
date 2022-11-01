#define INF 0x7f7f7f7f7f7fll
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

struct edge {
    int pre,e,r;
    ll c;
    bool v;
};

edge E[100000];
int last = 0,V[1000],m,n,s,t;
int h[1000],vh[1000];

void insert(int u,int v,ll w) {
    E[last].e = v;
    E[last].c = w;
    E[last].r = last + 1;
    E[last].pre = V[u];
    E[last].v = false;
    V[u] = last++;

    E[last].e = u;
    E[last].c = 0;
    E[last].r = last - 1;
    E[last].pre = V[v];
    E[last].v = true;
    V[v] = last++;
}

ll AugPath(int u,ll mf) {
    if (u == t)
        return mf;
    ll l = mf;
    int minh = n-1;
    for (int i = V[u];i != -1;i = E[i].pre)
        if (E[i].c) {
            if (h[E[i].e] + 1 == h[u]) {
                ll d = l < E[i].c ? l : E[i].c,f;
                if (d) d = AugPath(E[i].e,d);
                E[i].c -= d;
                E[E[i].r].c += d;
                l -= d;
                if (!l || h[s] >= n) return mf-l;
            }
            if (h[E[i].e] < minh) minh = h[E[i].e];
        }
    if (!(mf-l)) {
        vh[h[u]]--;
        if (!vh[h[u]]) h[s] = n;
        h[u] = ++minh;
        vh[h[u]]++;
    }
    return mf-l;
}

int main() {
    int nn;
    cin >> nn;
    s = 0; t = 2 * nn + 1;
    n = 2 * nn + 2;
    for (int i = 0;i < n;++i)
        V[i] = -1;
    last = 0;
    for (int i = nn+1;i <= 2*nn;++i)
        insert(i,t,INF);
    for (int m,a,i = 0;i < nn;++i)
    {
        cin >> m;
        for (int j = 0;j < m;++j)
        {
            cin >> a;
            insert(i+1,nn+a,INF);
        }
    }
    ll tot = 0;
    for (int w,i = 0;i < nn;++i)
    {
        cin >> w;
        tot += w;
        insert(s,i+1,INF-w);
    }
    memset(h,0,sizeof(h));
    memset(vh,0,sizeof(vh));
    vh[0] = n;
    ll flow = 0;
    while (h[s] < n) flow += AugPath(s,INF*2ll);
    cout << tot + flow - nn * INF << endl;
    return 0;
}