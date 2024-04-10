#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define fi first
#define se second

using namespace std;

ll n, m, k, i, j, l, r;
ll x[1001], y[1001];

bool isin(ll xx,ll yy)
{
    return (xx>=x[2] && xx<x[3] && yy>=y[2] && yy<y[3] ||
            xx>=x[4] && xx<x[5] && yy>=y[4] && yy<y[5]);
}

int main()
{
    for (int i = 0; i < 3; i++) cin >> x[i*2] >> y[i*2] >> x[i*2+1] >> y[i*2+1];
    bool tt=0;
    for (int i = x[0]; i < x[1]; i++)
    {
        if (!isin(i,y[0]) || !isin(i,y[1]-1)) {cout << "YES\n";exit(0);}
    }
    for (int i = y[0]; i < y[1]; i++)
    {
        if (!isin(x[0],i) || !isin(x[1]-1,i)) {cout << "YES\n";exit(0);}
    }
    cout << "NO\n";
    return 0;
}