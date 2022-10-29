#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, a[300005];
vector <pll> ans;
ll t[300005];

void swp(ll x,ll y)
{
    swap(a[x],a[y]);
    swap(t[a[x]],t[a[y]]);
    ans.pb(mp(x,y));
}

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[a[i]]=i;
    }
    for (int i = 1; i <= n; i++)
        if (t[i]!=i)
    {
        if (t[i]>n/2)
        {
            if (i<=n/2)
            {
                if (abs(t[i]-i)>=n/2)
                {
                    swp(i,t[i]);
                }else
                {
                    ll z=t[i];
                    swp(1,z);
                    swp(1,n);
                    swp(i,n);
                    swp(1,n);
                    swp(1,z);
                }
            }else
            {
                ll z=t[i];
                swp(1,z);
                swp(1,i);
                swp(1,z);
            }
        }else
        if (t[i]<=n/2)
        {
            if (i>n/2)
            {
                if (abs(t[i]-i)>=n/2)
                {
                    swp(t[i],i);
                }else
                {
                    ll z=t[i];
                    swp(z,n);
                    swp(1,n);
                    swp(1,i);
                    swp(1,n);
                    swp(z,n);
                }
            }else
            if (i<=n/2)
            {
                ll z=t[i];
                swp(z,n);
                swp(i,n);
                swp(z,n);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i].fi << " " << ans[i].se << "\n";
    //for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/