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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        if (t[a[i]]) continue;
        t[a[i]]=1;
        ll j=n-1;
        while (j>i && a[j]==a[i]) j--;
        ans=max(ans,j-i);
    }
    cout << ans;
    return 0;
}