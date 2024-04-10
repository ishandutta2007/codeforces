#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[1000001], b[1000001];
vector <ll> v, z;
string s;
ll tt[1000001];
ll d[1000001];

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];b[i]=a[i];}
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++)
    {
        if (b[i]==b[i-1]) b[i]=b[i-1]; else
        {
            ll p=b[i-1]+1;
            for (int j = 1; j <= n; j++) if (a[j]==b[i]) a[j]=p;
            b[i]=p;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ll p=0;
        for (int j = n; j >= i; j--)
        {
            if (tt[a[j]]) {p=j;break;}else tt[a[j]]++;
        }
        //cout << i << " " << p << "\n";
        ans=min(max(p-i+1,0ll),ans);
        if (ans==0){cout << 0;exit(0);}
        for (int j = n; j > max(p,(ll)i-1); j--) tt[a[j]]--;
        if (tt[a[i]]) break; else tt[a[i]]++;
    }
    cout << ans;
    return 0;
}