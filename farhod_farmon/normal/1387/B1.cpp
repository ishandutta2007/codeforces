#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int res;
vector < int > v[N];

void dfs(int x, int p)
{
        for(int y: v[x]){
                if(y == p) continue;
                dfs(y, x);
                if(a[y] == y){
                        res += 2;
                        swap(a[x], a[y]);
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= n; i++) a[i] = i;
        dfs(1, 1);
        if(a[1] == 1){
                swap(a[1], a[v[1][0]]);
                res += 2;
        }
        cout << res << "\n";
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
}