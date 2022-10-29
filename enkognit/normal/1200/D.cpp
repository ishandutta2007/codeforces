#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

int n, m, i, j, k, l, r, a[2001][2001];
int d[2001][10001];
pair<int,int> v[2001], z[2001];
int t[2001][10001];
string s;

void psh(ll nm,ll h)
{
    if (t[nm][h])
    {
        d[nm][h]+=t[nm][h];
        t[nm][h*2]+=t[nm][h];
        t[nm][h*2+1]+=t[nm][h];
        t[nm][h]=0;
    }
}

void update(ll nm, ll h,ll l,ll r,ll x,ll y)
{
    psh(nm,h);
    if (x>y) return;
    if (l==x && y==r)
    {
        t[nm][h]++;
        psh(nm,h);
        return;
    }
    ll w=(l+r)/2;
    update(nm,h*2,l,w,x,min(y,w));
    update(nm,h*2+1,w+1,r,max(x,w+1),y);
    d[nm][h]=max(d[nm][h*2],d[nm][h*2+1]);
}

int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++) a[i][j+1]=(s[j]=='B');
    }
    ll k=0;
    for (int i = 1; i <= n; i++)
    {
        int mn=1e9, mx=0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j]) mn=min(mn,j),mx=max(mx,j);
        }
        if (mn==1e9) k++;
        v[i]=mp(mn, mx);
    }
    //cout << 1;
    for (int i = 1; i <= n; i++)
    {
        int mn=1e9, mx=0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i]) mn=min(mn,j),mx=max(mx,j);
        }
        if (mn==1e9) k++;
        z[i]=mp(mn, mx);
    }
    //cout <<1;
    for (int i = 1; i <= n; i++)
    {
        ll x=max(v[i].se-m+1,1), y=v[i].fi;
        //cout << x << "-" << y << "\n";
        if (y<1e9)
        for (int j = max(i-m+1,1); j <= i; j++)
            update(j,1,1,n,x,y);
    }
    //cout <<1;
    for (int i = 1; i <= n; i++)
    {
        ll x=max(z[i].se-m+1,1), y=z[i].fi;
        //cout << x << "-" << y << "\n";
        if (y<1e9)
        for (int j = x; j <= y; j++)
            update(j,1,1,n,max(i-m+1,1),i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans=max(ans,(ll)d[i][1]);
    cout << ans+k;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/