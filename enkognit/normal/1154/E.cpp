#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, r, a[400001];
ll d[1000001];
ll t[500001];
vector <pll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll o=1;
    for (int i = 0; i < v.size(); i++)
        if (t[v[i].se]==0)
        {
            o++;
            o%=2;
            //cout << v[i].se << ": \n";
            t[v[i].se]=o+1;
            ll l=v[i].se, r=v[i].se, p;
            p=0;
            while (l>0 && p<k)
            {
                if (l-1-d[l-1]<0)break;
                //cout << l << " " << p << "\n";
                l--,l-=d[l],p++,t[l]=o+1;
            }
            p=0;
            while (r<n-1 && p<k)
            {
                if (r+1+d[r+1]>n-1)break;
                r++,r+=d[r],p++,t[r]=o+1;
            }
            if (!t[r])r--;
            if (!t[l])l++;
            l=max(l,0ll);
            r=min(r,n-1);
            //cout << l << "---" << r << "\n";
            if (l>0 && t[l-1])
            {
                l=l-d[l-1];
            }
            if (r<n-1 && t[r+1])
            {
                r=r+d[r+1];
            }
            ll u=r-l+1;
            d[l]=u, d[r]=u;
            //for (int i = 0; i < n; i++) cout << d[i] << " ";
            //cout << "\n";
            //for (int i = 0; i < n; i++) cout << t[i] << " ";
            //cout << "\n";
        }
    for (int i = 0; i < n; i++) cout << t[i];
    return 0;
}