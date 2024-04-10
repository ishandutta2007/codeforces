#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, k, ans, l, r, no, yes, x[1000001], y[1000001];
map<ll,bool> tt={};
string s, d;

int main()
{
    //freopen("roulette.in","r",stdin);
    //freopen("roulette.out","w",stdout);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ans=1;
    for (int i = 1; i <= n; i++)
    {
        if (x[i-1]==y[i-1])
        {
            ans+=min(x[i],y[i])-x[i-1];
        }else
        if (x[i-1]>y[i-1])
        {
            ans+=max(0ll,min(x[i],y[i])-x[i-1]+1);
        } else
        if (x[i-1]<y[i-1])
        {
            ans+=max(0ll,min(x[i],y[i])-y[i-1]+1);
        }
    }
    cout << ans;
    return 0;
}