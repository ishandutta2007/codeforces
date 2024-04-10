#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

int n, m, i, j, ans;
int d[30][1000001];
int t[30][1000001];
string s;
//bool t[x][y];

void push(ll c,ll h,ll l,ll r)
{
    //cout << l << " " << r << "\n";
    if (t[c][h]!=0)
    {
        if (t[c][h]==-1) d[c][h]=0; else d[c][h]=r-l+1;
        t[c][h*2]=t[c][h];
        t[c][h*2+1]=t[c][h];
        t[c][h]=0;
    }
}

void build(ll c,ll h,ll l,ll r)
{
    if (l==r)
    {
        if (s[l]==c+'a') d[c][h]=1;
        return;
    }
    ll w=(l+r)/2;
    build(c,h*2,l,w);
    build(c,h*2+1,w+1,r);
    d[c][h]=d[c][h*2]+d[c][h*2+1];
}

ll get(ll c,ll h,ll l,ll r,ll x,ll y)
{
    push(c,h,l,r);
    if (x>y) return 0;
    if (l==x && y==r) return d[c][h];
    ll w=(l+r)/2;
    ll o=get(c,h*2,l,w,x,min(y,w))+get(c,h*2+1,w+1,r,max(x,w+1),y);
    //d[c][h]=d[c][h*2]+d[c][h*2+1];
    return o;
}

void update(ll c,ll h,ll l,ll r,ll x,ll y, bool p)
{
    push(c,h,l,r);
    if (x>y) return;
    if (l==x && y==r)
    {
        if (p) t[c][h]=1; else t[c][h]=-1;
        push(c,h,l,r);
        //d[c][h]=d[c][h*2]+d[c][h*2+1];
        return;
    }
    ll w=(l+r)/2;
    update(c,h*2,l,w,x,min(y,w),p);
    update(c,h*2+1,w+1,r,max(x,w+1),y,p);
    d[c][h]=d[c][h*2]+d[c][h*2+1];
}

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n >> m;
    cin >> s;
    s=' '+s;
    for (int i = 0; i < 26; i++) build(i,1,1,n);
    //cout << get(0,1,1,n,1,1);
    for (int it = 0; it < m; it++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        if (h==1)
        {
            ll l=x;
            for (int i = 0; i < 26; i++)
            {
                ll p=get(i,1,1,n,x,y);
                if (!p) continue;
                //cout << (char)('a'+i) << " " << p << "\n";
                update(i,1,1,n,x,y,0);
                update(i,1,1,n,l,min(l+p-1,(ll)n),1);
                l+=p;
                l=min(l,(ll)n);
            }
        }else
        {
            ll l=x;
            for (int i = 25; i > -1; i--)
            {
                ll p=get(i,1,1,n,x,y);
                //cout << (char)('a'+i) << " " << p << "\n";
                if (!p) continue;
                //if (l+p-1>n) system("pause");
                update(i,1,1,n,x,y,0);
                update(i,1,1,n,l,min((ll)n,l+p-1),1);
                l+=p;
                l=min(l,(ll)n);
            }
        }

    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
            if (get(j,1,1,n,i,i))
        {
            cout << (char)('a'+j);
        }
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/