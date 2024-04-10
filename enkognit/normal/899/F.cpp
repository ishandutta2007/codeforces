#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, j, k, l, r, n1, n2, a[200001];
string s;
ll d[1000001];
vector <ll> v[100];
int tt[200001];
bool t[200001];

ll rfm(char x)
{
    if (x>='a' && x<='z') return x-'a';
    if (x>='A' && x<='Z') return x-'A'+30;
    if (x>='0' && x<='9') return x-'0'+60;
}

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=1;return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=d[h*2]+d[h*2+1];
}

void update(ll h,ll l,ll r,ll x)
{
    if (l==r) {d[h]=0;return;}
    ll w=(l+r)/2;
    if (w>=x) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h]=d[h*2]+d[h*2+1];
}

ll get(ll h,ll l,ll r,ll k,ll x)
{
    //if (x==1) cout << l << " " << r << " " << d[h*2] << "\n";
    if (l==r) return l;
    ll w=(l+r)/2;
    if (k+d[h*2]<x) return get(h*2+1,w+1,r,k+d[h*2],x); else return get(h*2,l,w,k,x);
}

int main()
{
    //freopen("packdel.in","r",stdin);
    //freopen("packdel.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) v[rfm(s[i])].pb(i);
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        ll l, r, c;
        char w;
        cin >> l >> r >> w;
        c = rfm(w);
        l = get(1,1,n,0,l), r = get(1,1,n,0,r);
        ll z = upper_bound(v[c].begin(), v[c].end(), l-1) - v[c].begin();
        //cout << l << " " << r << " " << w << " " << v[c][z] << "\n";
        while (z < v[c].size() && v[c][z] < l) z++;

        while (z < v[c].size() && v[c][z] <= r)
        {
            if (!t[v[c][z]])
            update(1,1,n,v[c][z]), t[v[c][z]]=1;
            z++;
        }
    }
    for (int i = 1; i <= n; i++) if (!t[i]) cout << s[i];
}