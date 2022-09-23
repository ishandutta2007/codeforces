#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int n;
int res[N];
int a[N];
int s[N];
int d[N];
int f[N][26];
int inf = 1e9;

void dfs(int x, int auto_x)
{
        if(x > 0 && a[x] > 0){
                d[x] = min(d[x], auto_x + 1);
        }
        auto_x = min(auto_x, d[x]);

        if(a[x] > 0){
                s[x] += 1;
                auto_x += 1;
                res[a[x]] = d[x];
        }

        for(int i = 0; i < 26; i++){
                int y = f[x][i];
                if(y == 0) continue;

                d[y] = min(d[y], d[x] + 1);
                dfs(y, auto_x);
                s[x] += s[y];
                auto_x += s[y];
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                char c;
                cin >> x >> c;
                f[x][c - 'a'] = i;

                d[i] = inf;
        }
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++){
                int x;
                cin >> x;
                a[x] = i;
        }

        dfs(0, inf);

        for(int i = 1; i <= k; i++) cout << res[i] << " ";
}