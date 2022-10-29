#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

ll n, m, l, r, x, y, a[300001];
bool t[300001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll l=1, r=n;
    while (l<r)
    {
        ll w=(l+r)/2+(l+r)%2;
        vector <ll> v={};
        for (int i = 0; i < w; i++) v.pb(a[i]);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll tt=0;
        ll k=0;
        for (int i = 0; i < w; i++)
        {
            if (k+v[i]>m) {tt=i+1;break;}
            if (i%2==1) k+=max(v[i],v[i-1]);
        }
        if (tt)
        {
            r=w-1;
            //cout << tt << "\n";
            //for (int i = 0; i < w; i++) cout << v[i]  << " ";
            //cout << "\n";
        } else l=w;
    }
    cout << l;
    return 0;
}