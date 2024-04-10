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

ll n, m, i, j, x, k, ans, nx[500050][22];
ll a[500050];
vector <pll> v;
//bool t[10000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x]=max(y,a[x]);
    }

    for (int i = 0; i < 500010; i++) a[i]=max(a[i],a[i-1]), nx[i][0]=max(a[i],(ll)i);

    for (int j = 1; j < 21; j++)
        for (int i = 0; i < 500010; i++)
            nx[i][j]=nx[nx[i][j-1]][j-1];

    for (int it = 0; it < m; it++)
    {
        ll x, y;
        cin >> x >> y;
        if (nx[x][20]<y) {cout << "-1\n";continue;}
        ll ans=1;
        for (int i = 19; i > -1; i--)
            if (nx[x][i] < y)
            {
                ans+=(1<<i);
                x=nx[x][i];
            }
        cout << ans << "\n";
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/