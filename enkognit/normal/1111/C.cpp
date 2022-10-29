#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, j, l, r, k, kol, A, B, len=pow(2,30);
vector <ll> b;
map<ll,ll> f, t, o;

ll rec(ll l,ll r,ll kol)
{
    if (kol==0) return A;
    if (l==r)
    {
        if (t[l]) return B*t[l]; else return A;
    }
    ll w=(l+r)/2, z=0;
    ll lr=upper_bound(b.begin(),b.end(),l-1)-b.begin(), rr=upper_bound(b.begin(),b.end(),r)-b.begin(),
    cr=upper_bound(b.begin(),b.end(),w)-b.begin();
    //if (b[rr]>r) rr--;
    //if (b[cr]>w) cr--;
    //if (b[lr]>=l) lr--;
    //cout << w << " " << o[w] << "\n";
    if (kol) z=kol*B*(r-l+1); else z=A;
    //cout << l << " " << w << " " << r << " " << lr << " "  << cr << " " << rr <<  "\n";

    return min(rec(l,w,max(cr-lr,0ll))+rec(w+1,r,max(rr-cr,0ll)),z);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k >> A >> B;
    len=pow(2,n);
    b.pb(0);
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        b.pb(x);
        t[x]++;
    }
    sort(b.begin(),b.end());
    b.pb(1e18);
    ll p=0;
    cout << rec(1,pow(2,n),k);
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/