#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

long long f[N];
long long mod = 1e9 + 7;
vector < long long > v;

void get_luck(long long x)
{
    if(x > 1e9)
        return;
    v.pb(x);
    get_luck(x * 10 + 4);
    get_luck(x * 10 + 7);
}

long long bpow(long long x, long long g)
{
    if(g == 0)
        return 1;
    else if(g == 1)
        return x;
    else if(g % 2)
        return (x * bpow(x, g - 1)) % mod;
    else
        return bpow((x * x) % mod, g / 2);
}

long long inv(long long x)
{
    return bpow(x, mod - 2);
}

long long C(long long n, long long k)
{
    if(k < 0 || k > n)
        return 0;
    return (f[n] * inv((f[n - k] * f[k]) % mod)) % mod;
}

long long n;
long long k;
long long a[N];
long long d[2020][2020];
map < long long, long long > co;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long unlucky = n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        co[a[i]]++;
    }
    f[0] = 1;
    for(long long i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % mod;
    get_luck(0);
    d[0][0] = 1;
    int sz = v.size() - 1;
    for(int i = 0; i <= sz; i++){
        unlucky -= co[v[i]];
        for(int j = 0; j <= sz; j++){
            d[i + 1][j] = (d[i + 1][j] + d[i][j]) % mod;
            d[i + 1][j + 1] = (d[i + 1][j + 1] + d[i][j] * co[v[i]]) % mod;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= sz; i++)
        ans = (ans + d[sz + 1][i] * C(unlucky, k - i)) % mod;
    cout << ans << endl;
}