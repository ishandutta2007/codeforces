#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define pll pair<ll,ll>
#define pld pair<ld,ld>

using namespace std;

ll n, m, k, l, r, ttt, x, y, i, T, t, j, kol, q;
ll a[1000001], b[100001], kl[1000001], ps[1000001];
ll d[1000001];

void build(int h,int l,int r)
{
    if (l==r) {d[h]=0;return;}
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=0;
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

void update(int h,int l,int r,int x,int k)
{
    //if (h==1) cout << x << " " << k << "\n";
    if (l==r) {d[h]=k;return;}
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=d[h*2]+d[h*2+1];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {cin >> a[i];ps[a[i]]=1e18;kl[a[i]]=i;}
        build(1,1,m);
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            ps[b[i]]=i;
        }
        ll mx=0, ans=0, p=0;
        for (int i = 1; i <= m; i++)
        {
            if (kl[b[i]]>mx)
            {
                mx=kl[b[i]];
                ans+=(kl[b[i]]-p-1)*2+1;
                p++;
            }else
            ans++,p++;
            //cout << i << "-" << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
4
2
3
8
5
10
1
11
15
*/