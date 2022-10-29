#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[1001][1001];
vector <ll> v, z;
string s;
ll tt[1000001];
ll d[1000001];

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    a[0][0]=8;
    a[0][1]=9;
    a[0][2]=1;
    a[0][3]=13;
    a[1][0]=3;
    a[1][1]=12;
    a[1][2]=7;
    a[1][3]=5;
    a[2][0]=0;
    a[2][1]=2;
    a[2][2]=4;
    a[2][3]=11;
    a[3][0]=6;
    a[3][1]=10;
    a[3][2]=15;
    a[3][3]=14;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll p=(i/4)*n/4+j/4;
            cout << a[i%4][j%4]+p*16 << " ";
        }
        cout << "\n";
    }
    return 0;
}