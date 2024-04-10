#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

ll n, m, l, r, x, y, a[1001][1001];

bool t[300001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            a[i][j]^=x;
        }
    //cout << "-------------------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (a[i][j])
            {
                if (i==n-1 || j==m-1) {cout << "No\n";exit(0);}
                a[i][j]^=1;
                a[i+1][j]^=1;
                a[i][j+1]^=1;
                a[i+1][j+1]^=1;
            }
    }
    cout << "Yes\n";
    return 0;
}