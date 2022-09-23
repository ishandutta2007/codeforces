#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n;
int a[N];
long long l[N];
long long used[N];
long long cycle_size;
long long fac[N];
long long mod = 1e9 + 7;

void dfs(long long x, long long g)
{
    if(used[x] == 2)
        return;
    if(used[x] == 1){
        if(cycle_size == 0)
            cycle_size = g - l[x];
        return;
    }
    used[x] = 1;
    l[x] = g;
    dfs(a[x], g + 1);
    used[x] = 2;
}

long long pw(long long x, long long g)
{
    if(g == 0)
        return 1;
    if(g % 2)
        return (x * pw(x, g - 1)) % mod;
    return pw((x * x) % mod, g / 2);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    sc("%d", &n);
    fac[0] = 1;
    for(long long i = 1; i <= n; i++){
        sc("%d", &a[i]);
        fac[i] = (1ll * i * fac[i - 1]) % mod;
    }
    long long ans = 1;
    long long L = n;
    for(long long i = 1; i <= n; i++){
        if(used[i] == 0){
            cycle_size = 0;
            dfs(i, 0);
            if(cycle_size == 0)
                continue;
            L -= cycle_size;
            long long cnt = 0;
            for(long long j = 1; j < cycle_size; j++){
                long long x = (fac[j] * fac[cycle_size - j]) % mod;
                x = (fac[cycle_size] * pw(x, mod - 2)) % mod;
                cnt = (cnt + x) % mod;
            }
            ans = (ans * cnt) % mod;
        }
    }
    long long pow = 1;
    for(long long i = 1; i <= L; i++)
        pow = (pow + pow) % mod;
    ans = (ans * pow) % mod;
    cout << ans << endl;
}