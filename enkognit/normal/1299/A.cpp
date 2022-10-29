#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()

using namespace std;

ll n, m, k, i, j, h, a[1000001], prl[1000001], prr[1000001];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    prl[0]=(1<<30)-1;
    for (int i = 1; i <= n; i++)
    {
        ll x=a[i], p=0;
        for (int j = 0; j < 30; j++)
        {
            if (x%2==0) p+=(1<<j);
            x/=2;
        }
        prl[i]=(prl[i-1]&p);
        //cout << i << " : " << p << "\n";
    }
    prr[n+1]=(1<<30)-1;
    for (int i = n; i > 0; i--)
    {
        ll x=a[i], p=0;
        for (int j = 0; j < 30; j++)
        {
            if (x%2==0) p+=(1<<j);
            x/=2;
        }
        prr[i]=(prr[i+1]&p);
    }
    ll o=0, mx=-1;
    for (int i = 1; i <= n; i++)
    {
        if ((a[i]&prl[i-1]&prr[i+1])>mx) mx=(a[i]&prl[i-1]&prr[i+1]), o=i;
        //cout << (a[i]&prl[i-1]&prr[i+1]) << " : " << i << "\n";
    }
    cout << a[o] << " ";
    for (int i = 1; i <= n; i++) if (i!=o) cout << a[i] << " ";
    return 0;
}
/*
*/