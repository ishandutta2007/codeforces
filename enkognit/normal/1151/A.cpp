#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, ans, k, l, r, i, j, a[300005], b[1005][1005];
string s;
vector<ll> c[300005];

ll get(char c, char u)
{
    if (c>u) swap(c,u);
    //cout << c << " " << u << "\n";
    return min(u-c, c-'A'+'Z'-u+1);
}

int main()
{
    //freopen("cipher.in","r",stdin);
    //freopen("cipher.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("rope.in","r",stdin);

    //freopen("rope.out","w",stdout);
    cin >> n;
    cin >> s;
    ll ans=1e18;
    for (int i = 0; i < n-3; i++)
    {
        ans=min(ans,get(s[i],'A')+get(s[i+1],'C')+get(s[i+2],'T')+get(s[i+3],'G'));
    }
    cout << ans;
    return 0;
}