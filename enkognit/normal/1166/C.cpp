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

const ll MOD=1000000007;

ll n, m, l, r, ans, k, p, a[200001];
vector <ll> v;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb(abs(a[i]));
    }
    sort(v.begin(),v.end());
    for (int i = 1; i < v.size(); i++)
    {
        ll l=0, r=i-1;
        while (l<r)
        {
            ll w=(l+r)/2;
            if (v[w]>=v[i]/2+(v[i])%2) r=w; else l=w+1;
            //cout << l << " " << r << "\n";
        }
        if (v[l]<v[i]/2+v[i]%2) l++;
        //cout << v[i] << " " << i-l << "\n";
        ans+=i-l;
    }
    cout << ans;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4
bokutachi wa benkyou ga dekinai
*/