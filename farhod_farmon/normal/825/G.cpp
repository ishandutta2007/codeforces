#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000011;
const int mod = 1e9 + 7;

using namespace std;

int n;
int q;
int res[N];
vector < int > v[N];

void dfs(int x, int p)
{
        res[x] = min(res[x], x);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                res[y] = res[x];
                dfs(y, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &q);
        for(int i = 1, x, y; i < n; i++){
                scanf("%d%d", &x, &y);
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int t, x;
        scanf("%d%d", &t, &x);
        x = x % n + 1;
        res[x] = x;
        dfs(x, x);
        int op = 1e9;
        int last = 0;
        for(int i = 2; i <= q; i++){
                scanf("%d%d", &t, &x);
                x = (x + last) % n + 1;
                if(t == 1){
                        op = min(op, res[x]);
                } else{
                        last = min(op, res[x]);
                        printf("%d\n", last);
                }
        }
}