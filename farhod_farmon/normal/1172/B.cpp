#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 10000011;
const long long mod = 998244353;

using namespace std;

int n;
long long d[N];
long long f[N];
vector < int > v[N];

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n){
                if(n & 1){
                        res = res * x % mod;
                }
                n /= 2;
                x = x * x % mod;
        }
        return res;
}

long long C(int n, int k)
{
        return f[n] * pw(f[k] * f[n - k] % mod, mod - 2);
}

long long get(int k)
{
        return f[k] * (k + 1) % mod;
}

void dfs(int x, int p)
{
        d[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                d[x] = d[x] * d[y] % mod;
        }
        if(x != p){
                d[x] = d[x] * get(v[x].size() - 1) % mod;
        } else{
                d[x] = d[x] * f[v[x].size()] % mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        f[0] = 1;
        for(int i = 1; i < N; i++){
                f[i] = f[i - 1] * i % mod;
        }
        dfs(1, 1);
        cout << d[1] * n % mod << "\n";
}