#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int c[N];
int d[N];
vector < int > v[N];

int read()
{
        int mask = 0, n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
                int x;
                scanf("%d", &x);
                mask |= (1 << x - 1);
        }
        return mask;
}

bool done[N];
int cost[N];

int get(int x)
{
        if(done[x]){
                return cost[x];
        }
        done[x] = true;
        for(int i = 0; i < (1 << 9); i++){
                if((x & i) == i){
                        cost[x] += a[i];
                }
        }
        return cost[x];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
                a[read()] += 1;
        }
        for(int i = 0; i < m; i++){
                scanf("%d", &c[i]);
                v[read()].push_back(i);
        }
        for(int i = 0; i < (1 << 9); i++){
                sort(v[i].begin(), v[i].end(), [&](int x, int y){return c[x] < c[y];});
        }
        pair < int, int > best = {0, -2e9 - 1};
        pair < int, int > res = {0, 1};
        for(int i = 0; i < (1 << 9); i++){
                if(v[i].empty()){
                        continue;
                }
                for(int j = 0; j < (1 << 9); j++){
                        if(v[j].empty()){
                                continue;
                        }
                        if(i == j){
                                if(v[i].size() == 1){
                                        continue;
                                }
                                pair < int, int > can = {get(i | j), - c[v[i][0]] - c[v[i][1]]};
                                if(can > best){
                                        best = can;
                                        res = {v[i][0], v[i][1]};
                                }
                                continue;
                        }
                        pair < int, int > can = {get(i | j), - c[v[i][0]] - c[v[j][0]]};
                        if(can > best){
                                best = can;
                                res = {v[i][0], v[j][0]};
                        }
                }
        }
        cout << res.fi + 1 << " " << res.se + 1 << "\n";
}