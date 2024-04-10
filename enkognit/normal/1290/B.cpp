#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double

using namespace std;

ll md1=1e9+9, md2=998244357, p1=8244357, p2=3131313;

ll n, m, k, i, j, h, a[1000001];
pll b[1000001];
string s;
ll d[1000001];

void build(int h,int l,int r)
{
    if (l==r) {d[h]^=(1<<(s[l]-'a'));return;}
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=d[h*2]|d[h*2+1];
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return (get(h*2,l,w,x,min(w,y))|get(h*2+1,w+1,r,max(x,w+1),y));
}

int bit_count(int h)
{
    ll x=h, o=0;
    while (x)
    {
        o+=x%2;
        x/=2;
    }
    return o;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    s=' '+s;
    n=s.size()-1;
    build(1,1,n);
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l==r) {cout << "Yes\n";continue;}
        ll p=get(1,1,n,l,r), u=bit_count(p);
        if (u>2) cout << "Yes\n"; else
        if (u==1) cout << "No\n"; else
        if (s[l]!=s[r]) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}
/*
*/