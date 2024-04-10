#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 1e9 + 7;

using namespace std;

long long pw(long long n, long long k)
{
        if(k == 0){
                return 1;
        }
        if(k % 2){
                return n * pw(n, k - 1) % mod;
        }
        else{
                return pw(n * n % mod, k / 2);
        }
}

int n;
int k;
bool used[N];
vector < int > v[N];

int dfs(int x)
{
        if(used[x]){
                return 0;
        }
        used[x] = 1;
        int res = 1;
        for(int y: v[x]){
                res += dfs(y);
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y, w;
                cin >> x >> y >> w;
                if(w == 0){
                        v[x].push_back(y);
                        v[y].push_back(x);
                }
        }
        long long res = pw(n, k);
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                res -= pw(dfs(i), k);
                if(res < 0){
                        res += mod;
                }
        }
        cout << res << "\n";
}