#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, i, j, k, r;
pll a[100001];
ll b[100001];
map<ll,ll> t;

int main()
{
    //freopen("cars.in","r",stdin);
    //freopen("cars.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> a[i].fi;a[i].se=i+1;}
    sort(a,a+n);
    ll mxkol=0, k=0, kol=0;
    for (int i = 0; i < n; i++)
    {
        ll x=a[i].se;
        if (b[x-1]==0 && b[x+1]==0)
        {
            t[1]++, b[x]=1;
            kol++;
            if (t[b[x]]==kol && kol>mxkol) mxkol=kol, k=a[i].fi+1;
        }else
        if (b[x-1]==0)
        {
            t[b[x+1]]--;
            t[b[x+1]+1]++;
            b[x]=b[x+1]+1;
            b[x+b[x+1]]++;
            if (t[b[x]]==kol && kol>mxkol) mxkol=kol, k=a[i].fi+1;
        }else
        if (b[x+1]==0)
        {
            t[b[x-1]]--;
            t[b[x-1]+1]++;
            b[x]=b[x-1]+1;
            b[x-b[x-1]]++;
            if (t[b[x]]==kol && kol>mxkol) mxkol=kol, k=a[i].fi+1;
        }else
        {
            ll k=b[x-1]+b[x+1]+1;
            t[b[x-1]]--;
            t[b[x+1]]++;
            b[x-b[x-1]]=k;
            b[x+b[x+1]]=k;
            t[k]++;
            kol--;
            if (t[k]==kol && mxkol<kol) k=a[i].fi+1, mxkol=kol;
        }
        /*for (int j = 1; j <= n; j++) cout << b[j] << " ";
        cout << "\n";*/
    }
    cout << k;
    return 0;
}