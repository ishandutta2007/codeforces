#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
const int N = 3e5 + 10;
int n, m;
char s[N];
vector<int> g[N];
int f[N][26];
int du[N];
queue<int> q;
int main() {	
    scanf("%d %d", &n, &m);	
    scanf(" %s", s + 1);	
    while (m --) {		
        int x, y;		
        scanf("%d %d", &x, &y);		
        g[x].push_back(y);		
        du[y] ++;	
    }	
    for (int i = 1; i <= n; i ++)		
        if (!du[i])	q.push(i);	
    while (q.size()) {		
        int u = q.front();		
        q.pop();		
        f[u][s[u] - 'a'] ++;		
        for (int i = 0; i < g[u].size(); i ++)		
        {			
            for (int j = 0; j < 26; j ++)				
                f[g[u][i]][j] = max(f[g[u][i]][j], f[u][j]);			
                if (!(--du[g[u][i]]))				
                    q.push(g[u][i]);		
        }	
    }	

    for (int i = 1; i <= n; i ++)		
        if (du[i])	{
            puts("-1");
            return 0;
        }	
    int ans = 0;	
    for (int i = 0; i < 26; i ++)		
        for (int j = 1; j <= n; j ++)			
            ans =max(ans, f[j][i]);	
    printf("%d\n", ans);	
    return 0;
}