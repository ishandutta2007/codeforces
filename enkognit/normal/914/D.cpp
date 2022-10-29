#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimise("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

//#define {a...} make_struct(a...)
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;
using namespace __gnu_pbds;

template <typename ENKOGNIT>
using ordered_set = tree<ENKOGNIT, null_type, less<ENKOGNIT>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, O, k, i, j, ans1, ans2, l, r, kl, OO, o;
pll zad;

string s[100001];
int a[500001];
vector<bool> tt[200001];
vector<set<pii> > si, sj;

int gcd(int x,int y)
{
    if (x==0 || y==0) return x+y;else return __gcd(x,y);
}

struct segment_tree
{
    int d[10000001];
    void build(int h,int l,int r)
    {
        if (l==r) {d[h]=a[l];return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=gcd(d[h*2],d[h*2+1]);
    }

    void update(int h,int l,int r,int x,int k)
    {
        if (l==r) {d[h]=k;return;}
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h]=gcd(d[h*2],d[h*2+1]);
    }

    int get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return gcd(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }

    bool check(int h,int l,int r,int x,int y,int k)
    {
        if (l==r) return true;
        int w=(l+r)/2;
        int o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
        if (o1%k && o2%k) return false;
        if (o1%k) return check(h*2,l,w,x,min(y,w),k); else return check(h*2+1,w+1,r,max(x,w+1),y,k);
    }
};

segment_tree g;

int main()
{
    //freopen("bomb.in","r",stdin);
    //freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    g.build(1,1,n);
    cin >> m;
    while (m--)
    {
        int t;
        cin >> t;
        if (t==1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (g.check(1,1,n,x,y,z)) cout << "YES\n"; else cout << "NO\n";
        }else
        {
            int x, y;
            cin >> x >> y;
            g.update(1,1,n,x,y);
        }
    }
    return 0;
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

*/