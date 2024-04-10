#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define MAXN 5000

using namespace std;

vector <int> adj[MAXN];
bool possible[MAXN+1];
bool pos[MAXN+1];

int dfs(int v, int parent, int n)
{
    if (parent == -1) {
        for (int i = 0; i <= n; i++)
            pos[i] = false;
        pos[0] = true;
    }

    int size = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        int v2 = adj[v][i];
        if (v2 != parent) {
            int res = dfs(v2, v, n);
            size += res;

            if (parent == -1) {
                for (int i = n; i >= res; i--)
                    pos[i] |= pos[i-res];
            }
        }
    }

    if (parent == -1) {
        for (int i = 0; i <= n; i++)
            possible[i] |= pos[i];
    }

    return size;
}

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 0; i <= n; i++)
        possible[i] = false;
    possible[0] = true;

    for (int i = 0; i < n; i++)
        dfs(i, -1, n);

    int npossible = 0;
    for (int i = 1; i < n-1; i++)
        if (possible[i])
            npossible ++;

    printf("%d\n", npossible);
    for (int i = 1; i < n-1; i++)
        if (possible[i])
            printf("%d %d\n", i, n-1-i);

    return 0;
}