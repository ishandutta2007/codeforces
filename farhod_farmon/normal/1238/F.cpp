#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int res;
int d[N];
vector < int > v[N];

void dfs(int x, int p)
{
        int ch = v[x].size() - (x != p), best = 0;
        d[x] = ch + 1;

        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                d[x] = max(d[x], d[y] + ch);
                res = max(res, best + d[y] + (int)v[x].size() - 1);
                best = max(best, d[y]);
        }
        res = max(res, d[x] + (x != p));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        while(q--){
                cin >> n;
                for(int i = 1; i <= n; i++){
                        d[i] = 0;
                        v[i].clear();
                }

                for(int i = 1; i < n; i++){
                        int x, y;
                        cin >> x >> y;
                        v[x].push_back(y);
                        v[y].push_back(x);
                }

                res = 0;
                dfs(1, 1);

                cout << res << "\n";
        }
}