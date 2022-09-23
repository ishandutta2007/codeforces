#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n, k;
int s[N];
int d[N];
bool used[N];
vector < int > v[N];

void dfs(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]) if(y != p){
                d[y] = d[x] + 1;
                dfs(y, x);
                s[x] += s[y];
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        vector < int > g;
        for(int i = 1; i <= n; i++){
                g.push_back(d[i] - (s[i] - 1));
        }
        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());
        long long res = 0;
        for(int i = 0; i < k; i++) res += g[i];
        cout << res << "\n";
}