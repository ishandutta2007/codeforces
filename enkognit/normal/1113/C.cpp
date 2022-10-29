#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, i, j, v, r, p, k, ans, a[500001];
string s;
map<ll,ll> t[2];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    t[1][0]=1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        k^=a[i];
        ans+=t[i%2][k];
        t[i%2][k]++;
    }
    cout << ans;
    return 0;
}