#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int c[N];
vector < int > v[N];

void dfs(int x, int col)
{
        c[x] = col;
        for(int y: v[x]) if(!c[y]){
                dfs(y, 3 - col);
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        int mask = 0, mx = n - 1;
        for(int i = 1; i <= n; i++){
                if(v[i].size() == 1){
                        mask |= c[i];
                }
                int cnt = 0;
                for(int j: v[i]){
                        if(v[j].size() == 1){
                                cnt += 1;
                        }
                }
                mx -= max(cnt - 1, 0);
        }
        int mn = 1;
        if(mask == 3){
                mn = 3;
        }

        cout << mn << " " << mx << "\n";
}