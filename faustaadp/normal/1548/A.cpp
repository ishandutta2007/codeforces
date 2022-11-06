#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, m;
ll ya[NN];
set<ll> st[NN];
ll has = 0;
void masuk(ll x, ll y)
{
    if(x > y)
        swap(x, y);
    if(ya[x])
    {
        ya[x] = 0;
        has--;
    }
    st[x].insert(-y);
    st[y].insert(-x);
}
void keluar(ll x, ll y)
{
    if(x > y)
        swap(x, y);
    st[x].erase(-y);
    st[y].erase(-x);
    if(ya[x] == 0 && (-(*st[x].begin()) <= x))
    {
        ya[x] = 1;
        has++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    has = n;
    for(ll i = 1; i <= n; i++)
        ya[i] = 1;
    for(ll i = 1; i <= m; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        masuk(ta, tb);
    }
    ll q;
    cin >> q;
    while(q--)
    {
        ll ta;
        cin >> ta;
        if(ta == 1)
        {
            ll x, y;
            cin >> x >> y;
            masuk(x, y);
        }
        else
        if(ta == 2)
        {
            ll x, y;
            cin >> x >> y;
            keluar(x, y);
        }
        else
            cout << has << "\n";
    }
}