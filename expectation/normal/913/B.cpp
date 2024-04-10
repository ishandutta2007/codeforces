#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

vector<int> g[3000];
int n;
int c[3000];
bool ok = 1;

void dfs(int v)
{
    int q = 0;
    FOR (i,0,g[v].size())
    {
        dfs(g[v][i]);
        q += c[g[v][i]];
    }
    if (!g[v].size()) c[v] = 1;
    else
    {
        if (q < 3) ok = 0;
    }
}

int main()
{
    cin >> n;
    FOR (i,1,n)
    {
        int a;
        cin >> a; a--;
        g[a].push_back(i);
    }
    dfs(0);
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}