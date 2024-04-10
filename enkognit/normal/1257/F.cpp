#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, s, m, T, k, l, r, i, j, mn, mx, kol=0, a[400], mask, d[2000001], ans=-1;
vector <ll> v;
vector <pair<vector<ll>, ll > > z;

void rec1(vector <ll> v,int l,ll mask)
{
    //cout << l << " " << mask << "\n";
    //vector <int> b=v;
    if (l==16)
    {
        ll mn=1e18;
        //if (16382==mask) cout << v[0] << " " << v[1] << "\n";
        for (int i = 0; i < n; i++) mn=min(mn, (ll)v[i]);
        for (int i = 0; i < n; i++) v[i]-=mn;
        /*if (mask==1)
        {
            cout << mask << " : ";
            for (int i = 0; i < n; i++) cout << v[i] << " ";
            cout << "\n";
        }*/
        z.pb(mp(v,mask));
        return;
    }
    rec1(v,l+1,mask);
    //v=b;
    for (int i = 0; i < n; i++)
        if ((bool)(a[i]&(1<<l))==1)
            v[i]--; else v[i]++;
    rec1(v,l+1,mask^(1<<l));
}

void rec2(vector <ll> v,int l,ll mask)
{
    //if (mask>1073741823) return;
    ll p=l;
    if (l==30)
    {
        ll mx=0;
        for (int i = 0; i < n; i++) mx=max(mx, (ll)v[i]);
        for (int i = 0; i < n; i++) v[i]=mx-v[i];
        /*if (mask==0)
        {
            cout << "0 : ";
            for (int i = 0; i < n; i++) cout << v[i] << " ";
            cout << "\n";
        }*/
        //sort(v.begin(),v.end());
        ll l=0, r=z.size()-1;
        while (l<r)
        {
            ll w=(l+r)/2;
            bool tt=0;
            for (int i = 0; i < n; i++)
                if (v[i]>z[w].fi[i]) {l=w+1;tt=1;break;} else
                if (v[i]<z[w].fi[i]) {r=w-1;tt=1;break;}
            if (!tt) {cout << (mask^(z[w].se));exit(0);}
        }
        bool tt=0;
        for (int i = 0; i < n; i++)
            if (v[i]>z[l].fi[i]) {tt=1;break;} else
            if (v[i]<z[l].fi[i]) {tt=1;break;}
        if (!tt) {cout << (mask^(z[l].se));exit(0);}
        return;
    }
    rec2(v,l+1,mask);
    for (int i = 0; i < n; i++)
        if ((bool)(a[i]&(1<<p))==1)
            v[i]--; else v[i]++;
    rec2(v,l+1,mask^(1<<p));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll mx=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb(0);
        ll p=0, x=a[i];
        while (x)
        {
            p+=x%2;
            x/=2;
        }
        mx=max(mx,p);
    }
    rec1(v,0,0);
    sort(z.begin(),z.end());

    for (int i = 0; i < n; i++)
    {
        ll p=0, x=a[i];
        while (x)
        {
            p+=x%2;
            x/=2;
        }
        v[i]=p-mx;
        //cout << v[i] << " ";
    }
    //cout << "\n";
    rec2(v,16,0);
    cout << -1;
    return 0;
}