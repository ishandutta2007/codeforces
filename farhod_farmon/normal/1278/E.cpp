#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500050;

using namespace std;

int n;
int l[N];
int r[N];
int G;
vector < int > v[N];

void dfs(int x, int p)
{
        reverse(v[x].begin(), v[x].end());
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                l[y] = ++G;
        }
        r[x] = ++G;

        reverse(v[x].begin(), v[x].end());
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        l[1] = ++G;
        dfs(1, 1);

        for(int i = 1; i <= n; i++){
                cout << l[i] << " " << r[i] << "\n";
        }
}