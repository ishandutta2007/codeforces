#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int q;
int c[N];
int a[N];
int b[N];
int p[N];
int res[N];
bool dead[N];
bool used[N];
vector < int > v[N];

bool dfs(int x)
{
        if(used[x]){
                return false;
        }
        used[x] = 1;
        for(int y: v[x]){
                if(p[y] == -1 || dfs(p[y])){
                        p[y] = x;
                        return true;
                }
        }
        return false;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        cin >> q;
        for(int i = 1; i <= q; i++){
                cin >> c[i];
                dead[c[i]] = 1;
        }
        for(int i = 1; i <= m; i++){
                p[i] = -1;
        }
        for(int i = 1; i <= n; i++){
                if(dead[i]){
                        continue;
                }
                v[a[i]].push_back(b[i]);
        }
        for(int i = q; i >= 1; i--){
                res[i] = res[i + 1];
                int x = c[i];
                for(int j = 0; j <= 5001; j++){
                        used[j] = 0;
                }
                while(dfs(res[i])){
                        res[i]++;
                        for(int j = 0; j <= 5001; j++){
                                used[j] = 0;
                        }
                }
                v[a[x]].push_back(b[x]);
        }
        for(int i = 1; i <= q; i++){
                cout << res[i] << "\n";
        }
}