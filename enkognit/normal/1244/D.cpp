#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, ans[1000001], c[4][1000001], p11[100001], p22[100001], p33[100001], p44[100001], p55[100001], p66[100001];
bool tt[1000001];
vector <ll> v, q[100005];

void dfs(ll h)
{
    v.pb(h);
    tt[h]=1;
    for (int i = 0; i < q[h].size(); i++)
        if (!tt[q[h][i]]) dfs(q[h][i]);
}

int main()
{

    ios_base::sync_with_stdio(0);
    //for (int i = 0; i < n; i++) cin >> p[i];
    //for (int i = 0; i < n; i++) cout << p[i] << " ";
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[0][i];
    for (int i = 1; i <= n; i++) cin >> c[1][i];
    for (int i = 1; i <= n; i++) cin >> c[2][i];
    for (int i = 1; i< n; i++)
    {
        ll x, y;
        cin >> x >> y;
        q[x].pb(y);
        q[y].pb(x);
    }
    ll p=1;
    for (int i = 1; i <= n; i++)
    {
        if (q[i].size()>2){cout << -1;exit(0);}
        if (q[i].size()==1) p=i;
    }
    dfs(p);
    ll p1=0, p2=0, p3=0,
        p4=0, p5=0, p6=0;
    for (int i = 0; i < v.size(); i+=3)
    {
        if (v.size()>i)
        {
            p1+=c[0][v[i]];p11[i]=1;
            p2+=c[0][v[i]];p22[i]=1;
            p3+=c[1][v[i]];p33[i]=2;
            p4+=c[1][v[i]];p44[i]=2;
            p5+=c[2][v[i]];p55[i]=3;
            p6+=c[2][v[i]];p66[i]=3;
        }
        if (v.size()>i+1)
        {
            p1+=c[1][v[i+1]];p11[i+1]=2;
            p2+=c[2][v[i+1]];p22[i+1]=3;
            p3+=c[0][v[i+1]];p33[i+1]=1;
            p4+=c[2][v[i+1]];p44[i+1]=3;
            p5+=c[0][v[i+1]];p55[i+1]=1;
            p6+=c[1][v[i+1]];p66[i+1]=2;
        }
        if (v.size()>i+2)
        {
            p1+=c[2][v[i+2]];p11[i+2]=3;
            p2+=c[1][v[i+2]];p22[i+2]=2;
            p3+=c[2][v[i+2]];p33[i+2]=3;
            p4+=c[0][v[i+2]];p44[i+2]=1;
            p5+=c[1][v[i+2]];p55[i+2]=2;
            p6+=c[0][v[i+2]];p66[i+2]=1;
        }
    }
    ll z=min(min(min(p1,p2),p3),min(min(p4,p5),p6));
    if (z==p1)
    {
        for (int i = 0; i < v.size(); i++) ans[v[i]]=p11[i];
    }else
    if (z==p2)
    {
        for (int i = 0; i < v.size(); i++) ans[v[i]]=p22[i];
    }else
    if (z==p3)
    {
        for (int i = 0; i < v.size(); i++) ans[v[i]]=p33[i];
    }else
    if (z==p4)
    {
        for (int i = 0; i < v.size(); i++) ans[v[i]]=p44[i];
    }else
    if (z==p5)
    {
        for (int i = 0; i < v.size(); i++) ans[v[i]]=p55[i];
    }else
    if (z==p6)
    {
        for (int i = 0; i < v.size(); i++) ans[v[i]]=p66[i];
    }
    cout << z << "\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/