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

ll n, m, i, j, k, l, r, pb, pa1, pa2;
string s;

struct uu
{
    ll a,b,c;
};

uu d[5000001];

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h].b=(s[l]=='(');d[h].c=(s[l]==')');return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    ll o=min(d[h*2].b,d[h*2+1].c);
    d[h].a=d[h*2].a+d[h*2+1].a+o;
    d[h].b=d[h*2].b+d[h*2+1].b-o;
    d[h].c=d[h*2].c+d[h*2+1].c-o;
}

uu get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return {0,0,0};
    if (l==x && y==r) return d[h];
    ll w=(l+r)/2;

    uu p1=get(h*2,l,w,x,min(w,y)), p2=get(h*2+1,w+1,r,max(w+1,x),y);

    ll o=min(p1.b,p2.c);
    ll a=p1.a+p2.a+o;
    ll b=p1.b+p2.b-o;
    ll c=p1.c+p2.c-o;
    return {a,b,c};
}

int main()
{
    //freopen("packdel.in","r",stdin);
    //freopen("packdel.out","w",stdout);
    cin >> s;
    build(1,0,s.size()-1);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << get(1,0,s.size()-1,x-1,y-1).a*2 << "\n";
    }
}