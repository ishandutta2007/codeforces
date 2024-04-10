#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll mo = 998244353;
ll k, A, h;
ll n, nn;
ll me[NN];
ll wi[NN];
map<ll, ll> mep;
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1;
    else
    {
        ll tmp = powo(A, B / 2);
        tmp = (tmp * tmp) % mo;
        if(B % 2 == 1)
            tmp = (tmp * A) % mo;
        return tmp;
    }
}
void gen(ll mask, ll W, ll tam)
{
    for(ll i = 1; i <= n / 2; i++)
        me[i] = 0;
    for(ll i = nn - 1; i >= 0; i--)
    {
        if(i * 2 + 1 >= nn)
        {
            ll idx = nn - i - 1;
            if(mask & (1 << i))
                wi[i] = idx * 2 + 2; 
            else
                wi[i] = idx * 2 + 1; 
        }
        else
        {
            if(mask & (1 << i))
            {
                wi[i] = wi[i * 2 + 1];
            }
            else
            {
                wi[i] = wi[i * 2 + 2];
            }
        }
        me[wi[i]]++;
    }
    for(ll i = 1; i <= n / 2; i++)
    {
        ll xx = (1 << (k - me[i] - 1)) + 1;
        if(xx == 2 && W == 1)
            xx--;
        // jum = (jum + i * powo(A, xx)) % mo;
        // cout << i << " " << xx << "\n";
        cout << xx << " ";
    }
}
void cek1(ll W, ll mask)
{
    for(ll i = 1; i <= n / 2; i++)
        me[i] = 0;
    for(ll i = nn - 1; i >= 0; i--)
    {
        if(i * 2 + 1 >= nn)
        {
            ll idx = nn - i - 1;
            if(mask & (1 << i))
                wi[i] = idx * 2 + 2; 
            else
                wi[i] = idx * 2 + 1; 
        }
        else
        {
            if(mask & (1 << i))
            {
                wi[i] = wi[i * 2 + 1];
            }
            else
            {
                wi[i] = wi[i * 2 + 2];
            }
        }
        me[wi[i]]++;
    }
    ll jum = 0;
    for(ll i = 1; i <= n / 2; i++)
    {
        ll xx = (1 << (k - me[i] - 1)) + 1;
        if(xx == 2 && W == 1)
            xx--;
        jum = (jum + i * powo(A, xx)) % mo;
        // cout << i << " " << xx << "\n";
    }
    mep[jum] = mask + 1;
    // cout << jum << "\n";
    // cout << "\n";
}
void cek2(ll W, ll mask)
{
    for(ll i = 1; i <= n / 2; i++)
        me[i] = 0;
    for(ll i = nn - 1; i >= 0; i--)
    {
        if(i * 2 + 1 >= nn)
        {
            ll idx = nn - i - 1;
            if(mask & (1 << i))
                wi[i] = idx * 2 + 2; 
            else
                wi[i] = idx * 2 + 1; 
        }
        else
        {
            if(mask & (1 << i))
            {
                wi[i] = wi[i * 2 + 1];
            }
            else
            {
                wi[i] = wi[i * 2 + 2];
            }
        }
        me[wi[i]]++;
    }
    ll jum = 0;
    for(ll i = 1; i <= n / 2; i++)
    {
        ll xx = (1 << (k - me[i] - 1)) + 1;
        if(xx == 2 && W == 1)
            xx--;
        jum = (jum + (i + n / 2) * powo(A, xx)) % mo;
        // cout << i + n / 2<< " " << xx << "\n";
    }
    ll sisa = (h - jum + mo) % mo;
    if(mep[sisa] != 0)
    {
        gen(mep[sisa] - 1, 1 - W, 0);
        gen(mask, W, n / 2);
        cout << "\n";
        exit(0);
        // cout << mep[sisa] << " " << mask << "\n";
    }
    // mep[jum] = mask;
    // cout << jum << "\n";
    // cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> k >> A >> h;
    n = (1 << k);
    nn = (n - 2) / 2;
    for(ll i = 0; i < (1 << nn); i++)
    {
        cek1(1, i);
    }
    for(ll i = 0; i < (1 << nn); i++)
    {
        cek2(0, i);
    }
    mep.clear();
    for(ll i = 0; i < (1 << nn); i++)
    {
        cek1(0, i);
    }
    for(ll i = 0; i < (1 << nn); i++)
    {
        cek2(1, i);
    }
    cout << "-1" << "\n";
}