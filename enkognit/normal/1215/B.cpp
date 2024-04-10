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

ll n, m, i, p, k, T, j, y, kol, a[1000001];
vector <ll> v, c[300001];
bool tt[1000001];
ll t1[1000001], t2[1000001];
vector <ll> z[3];
string s, d;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    v.pb(0);
    ll o=0, y=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x<0)tt[i]=1, o++; else y++;
    }
    v.pb(n);
    ll p=0, ans2=0, t[2];
    t[0]=0,t[1]=0;
    for (int i = 1; i <= n; i++)
    {
        p+=tt[i];
        t1[i]=t1[i-1];
        t2[i]=t2[i-1];
        if (p%2) t1[i]++; else t2[i]++;
    }
    ll ans1=0;
    ll l=0;
    for (int i = 1; i <= n; i++)
    {
        //cout << t1[i] << " " << t2[i] << "\n";
        l+=tt[i];
        if (l%2) ans2+=t2[i]+1, ans1+=t1[i]-1; else ans2+=t1[i],ans1+=t2[i];
    }
    cout << ans2 << " " << ans1 << "\n";
    return 0;
}