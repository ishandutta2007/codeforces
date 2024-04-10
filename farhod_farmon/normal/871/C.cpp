#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int G;
vector < int > v[N];
map < int, int > A, B;
bool used[N], cyc;
int p[N], c;

void dfs(int x, int p)
{
        used[x] = true;
        c += 1;
        for(int y: v[x]){
                if(y == p) continue;
                if(used[y]) cyc = true;
                else dfs(y, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                if(!A[x]) A[x] = (++G);
                if(!B[y]) B[y] = (++G);
                x = A[x], y = B[y];

                v[x].push_back(y);
                v[y].push_back(x);
        }

        p[0] = 1;
        for(int i = 1; i < N; i++) p[i] = (p[i - 1] * 2) % mod;
        int res = 1;
        for(int i = 1; i <= G; i++){
                if(used[i]) continue;
                cyc = 0, c = 0;
                dfs(i, i);
                int cur = p[c] - ((int)cyc ^ 1);
                res = 1ll * res * cur % mod;
        }
        if(res < 0) res += mod;
        cout << res << "\n";
}