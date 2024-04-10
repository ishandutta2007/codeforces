#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, k, ans, l, r, no, yes, a[1000001];
map<ll,bool> tt={};
string s, d;

int main()
{
    //freopen("roulette.in","r",stdin);
    //freopen("roulette.out","w",stdout);
    ios_base::sync_with_stdio(0);
    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    ll ans=(w1+2+2*h1+w2+2+2*h2);
    cout << ans+abs(w1-w2);
    return 0;
}