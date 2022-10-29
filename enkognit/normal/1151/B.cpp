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

ll n, m, ans, k, l, r, i, j, a[1005][1005], b[1005][1005];
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
    cin >> n >> m;
    ll x=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
        x^=a[i][0];
    }
    if (x>0)
    {
        cout << "TAK\n";
        for (int i = 0; i < n; i++) cout << "1 ";
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        x^=a[i][0];
        for (int j = 1; j < m; j++)
            if ((x^a[i][j])>0)
            {
                cout << "TAK\n";
                for (int u = 0; u < n; u++) if (u==i) cout << j+1 << " "; else cout << "1 ";
                exit(0);
            }
        x^=a[i][0];
    }
    cout << "NIE";
    return 0;
}