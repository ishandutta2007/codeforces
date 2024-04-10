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

ll a[1000001], n, b[1001][1001];
map<ll,ll> t;
set<ll> s;
bool tt, tl;

int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll k=1, l=1, r=1;
    for (int i = 0; i < n*n; i++) {cin >> a[i];t[a[i]]++;s.insert(a[i]);}
    for (auto e : s)
    {
        if (t[e]%2)
        {
            if (n%2 && b[n/2+1][n/2+1]==0) b[n/2+1][n/2+1]=e; else {cout << "NO\n";exit(0);}
            t[e]--;
        }
        ll m=n/2;
        if (t[e]>3 && !tt)
        {
            while (k<=(m)*(m) && t[e]>3)
            {
                b[(k-1)/m+1][k-(k-1)/m*m]=e;
                b[n-(k-1)/m][k-(k-1)/m*m]=e;
                b[(k-1)/m+1][n-k+(k-1)/m*m+1]=e;
                b[n-(k-1)/m][n-k+(k-1)/m*m+1]=e;
                k++;
                //cout << k << "\n";
                t[e]-=4;
            }
            if (k>m*m) tt=1;
        }
        if (n%2)
        {
            while (l<m+1 && t[e]>1)
            {
                b[l][m+1]=e;
                b[n-l+1][n/2+1]=e;
                l++;
                t[e]-=2;
            }
            while (r<n/2+1 && t[e]>1)
            {
                b[n/2+1][r]=e;
                b[n/2+1][n-r+1]=e;
                r++;
                t[e]-=2;
            }
        }
        //cout << e << " " << t[e] << "\n";
    //    for (int i = 1; i <= n; i++)
    //{for (int j = 1; j <= n; j++) cout << b[i][j] << " ";cout << "\n";}
    //system("pause");
        if (t[e]>0) {cout << "NO\n";exit(0);}
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {for (int j = 1; j <= n; j++) cout << b[i][j] << " ";cout << "\n";}
    return 0;
}