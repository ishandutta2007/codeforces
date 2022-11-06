#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
const ll mo = 998244353;
ll n, a[NN], p[NN], C[5050][5050];
ll solve1()
{
    sort(a + 1, a + 1 + n);
    for(ll i = 1; i <= n; i++)
        p[i] = a[i];
    cout << "\n";
    for(ll i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
    ll ret = 0;
    do
    {
        ll tam = 1;

        for(ll i = 2; i < n; i += 2)
        {
            if(p[i - 1] >= p[i])
            {
                // cout << i - 1 << " dan " << i << "\n";
                tam = 0;
            }
            if(p[i + 1] >= p[i])
            {
                // cout << i + 1 << " dan " << i << "\n";
                tam = 0;
            }
            if(p[i + 2] <= p[i])
            {
                // cout << i - 2 << " dan " << i << "\n";
                tam = 0;
            }
        }
        if(p[n - 1] >= p[n])
            tam = 0;
        if(tam)
        {
            for(ll i = 1; i <= n; i++)
                cout << p[i] << " ";
             cout << "\n";
        }
        ret += tam;
    }
    while(next_permutation(p + 1, p + 1 + n));
    cout << "\n";
    return ret;
}
ll m, nx[NN], d[5050][5050], jen[NN], cnt[NN], F[NN];
ll depe(ll pos, ll udah)
{
    ll &ret = d[pos][udah];
    if(pos == n)
    {
        return (udah == (m - 1));
    }
    if(ret == -1)
    {
        ret = depe(nx[pos], udah);
        if(udah == 0)
        {
            ll tam = ((pos - 1) * (pos - 2)) % mo;
            if(tam > 0)
                ret = (ret + depe(nx[pos], udah + 1) * (tam * cnt[pos]) % mo) % mo;
        }
        else
        {
            ll sisa = (pos - 1) - udah * 2 - 1;
            // cout << pos << " " << udah << "  " << sisa << " " << ret << "_\n";
            if(sisa >= 1)
                ret = (ret + depe(nx[pos], udah + 1) * ((sisa * cnt[pos]) % mo)) % mo;
        }
        // cout << pos << " " << udah << " " << ret << "\n";
    }
    return ret;
}
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1;
    else
    {
        ll tmp = powo(A, B / 2);
        tmp = (tmp * tmp) % mo;
        if(B & 1)
            tmp = (tmp * A) % mo;
        return tmp;
    }
}
ll solve2()
{   
    if(a[n] == a[n - 1])
        return 0;
    m = n / 2;
    for(ll i = 1; i <= n; i++)
        for(ll j = 0; j <= n; j++)
            d[i][j] = -1;
    ll lst = 0;
    ll Z = 1;
    for(ll i = 1; i <= n; i++)
    {
        if(i == 1 || a[i] != a[i - 1])
        {
            nx[lst] = i;
            cnt[lst] = (i - lst);
            lst = i;
        }
    }
    lst = 0;
    // for(ll i = 1; i <= n; i++)
        // cout << i << " " << cnt[i] << "_\n";
    for(ll i = 1; i <= n; i++)
        if(i == n || a[i] != a[i + 1])
        {
            // cout << i - lst << "__\n";
            Z = (Z * powo(F[i - lst], mo - 2)) % mo;
            lst = i;
        }
    // Z = 1;
    nx[lst] = n;
    return (depe(1, 0) * Z) % mo;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    F[0] = 1;
    for(ll i = 1; i <= 5000; i++)
        F[i] = (F[i - 1] * i) % mo;
    ll T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        // n = 8;
        for(ll i = 1; i <= n; i++)
        {
            // a[i] = rand() % n + 1;
            cin >> a[i];
        }
        // ll J1 = solve1();
        ll J2 = solve2();
        // cout << J1 << "\n";
        cout << J2 << "\n";
        // if(J1 != J2)
        // {
            // break;
        // }
    }
}