#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 5020
using namespace std;

vector<int> e[N];
bool f[N][N], h[N];
vector<int> g;

void DFS(bool *u, int x)
{
    int i;

    if(u[x])
        return;
    u[x] = true;

    for(i = 0; i < (signed)e[x].size(); i ++)
        DFS(u, e[x].at(i));

    return;
}

int main(void)
{
    int n, m, s, u, v;
    int i, j;

    cin >> n >> m >> s;
    s --;
    while(m --)
    {
        cin >> u >> v;
        e[-- u].push_back(-- v);
    }

    for(i = 0; i < n; i ++)
        DFS(f[i], i);
    for(i = 0; i < n; i ++)
        if(!f[s][i])
            g.push_back(i);

    for(i = 0; i < (signed)g.size(); i ++)
        for(j = 0; j < (signed)g.size(); j ++)
            if(i != j)
            {
                if(f[g.at(i)][g.at(j)] && !h[i])
                    h[j] = true;
                else if(f[g.at(j)][g.at(i)] && !h[j])
                    h[i] = true;
            }
    for(i = s = 0; i < (signed)g.size(); i ++)
        s += h[i];
    cout << g.size() - s << endl;

    return 0;
}