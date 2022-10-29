#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kl, x, y, a[1000001];
vector <ll> c[100005];

bool tt[1000001];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll j=1;
    for (int i = 1; i <= 1000000; i++)
    {
        ll p=n-m*i;
        if (p<=0) break;
        ll j=(1<<30), u=0, r=0, y=30;
        while (p)
        {
            if (p>=j) p-=j, u++, r+=y;
            j/=2, y--;
        }
        //if (i==1) cout << u << " " << r << "\n";
        if (u<=i && u+r>=i) {cout << i;exit(0);}
    }
    cout << -1;
    return 0;
}