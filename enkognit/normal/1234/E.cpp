#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD = 1000000007;

ll n, k, l, m, r, i, j, x, y, ans, a[300001];
string s;
ll d[3000001];

void update(ll h,ll l,ll r,ll x,ll y,ll k)
{
    if (x>y) return;
    if (l==x && y==r)
    {
        //if (x==y && x==3)cout << h << "\n";
        d[h]+=k;
        return;
    }
    ll w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
}

ll get(ll h,ll l,ll r,ll x)
{
    if (l==r) {return d[h];}
    ll w=(l+r)/2;
    if (x<=w) return get(h*2,l,w,x)+d[h]; else return get(h*2+1,w+1,r,x)+d[h];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m-1; i++)
    {
        ll x=a[i], y=a[i+1];
        if (x==y) continue;
        if (x>y) swap(x,y);
        ans+=y-x;
        update(1,1,n,x+1,y-1,1);
        update(1,1,n,x,x,1-x);
        update(1,1,n,y,y,y-2*x);
    }
    //cout << 1;
    for (int i = 1; i <= n; i++)
    {
        cout << ans-get(1,1,n,i) << " ";
    }
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/