#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

vector<int> e[100007];

bool v[100007];
vector<int> gu, sp;
int n, m, k;

void dfs(int u, int lim)
{
    v[u] = true;
    for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); ++it)
        if (!v[*it] && sp[u]+sp[*it] < lim)
            dfs(*it, lim);
}

bool go(int lim, int s, int t)
{
    REP(i, n) v[i] = false;
    dfs(s, lim);
    return v[t];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    gu.resize(k);
    sp.resize(n);
    REP(i, k) cin >> gu[i];
    REP(i, k) --gu[i];
    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int s, t;
    cin >> s >> t;
    --s, --t;
    gu.push_back(s);
    gu.push_back(t);
    REP(i, n) sp[i] = 0x3f3f3f3f;
    queue<int> q;
    REP(i, k+2) sp[gu[i]] = 0, q.push(gu[i]);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (vector<int>::iterator it = e[now].begin(); it != e[now].end(); ++it)
            if(sp[*it] > sp[now] + 1)
            {
                sp[*it] = sp[now]+1;
                q.push(*it);
            }
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (go(mid,s,t))
            r = mid;
        else l = mid+1;
    }
    if (!go(l, s, t)) l = -1;
    cout << l << endl;
    return 0;
}