#include<iostream>
#define ll long long
const ll mod = 1000003;
using namespace std;

ll a[1000010] = {1, 1}, b[1000010] = {1, 1}, d[1000010] = {1, 1};

void clear()
{
    for(int i = 2; i <= 1000000; i++)
    {
        b[i] = i * b[i - 1] % mod;
        a[i] = (mod - mod / i) * a[mod % i] % mod;
        d[i] = d[i - 1] * a[i] % mod;
    }
}

ll C(ll n, ll m)
{
    return b[n] * d[m] % mod * d[n - m] % mod;
}

int main()
{
    clear();
    ll n, c, ans = 0;
    cin >> n >> c;
    for(ll i = 1; i <= n; i++)
    {
        ans += C(i + c - 1, c - 1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}