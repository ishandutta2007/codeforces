#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, k, l, r, a[300001], d[1000001];
pll b[200001];
bool tt[1000001];
string s;


int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, p=0;
        cin >> n >> m >> k;
        p=m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        bool tt=0;
        for (int i = 1; i < n; i++)
        {
            if (a[i]>max(a[i+1]-k,0ll)) p+=a[i]-max(a[i+1]-k,0ll),a[i]=max(a[i+1]-k,0ll);else
            {
                if (max(a[i+1]-a[i]-k,0ll)>p) {tt=1;break;}else
                   p-=max(a[i+1]-a[i]-k,0ll);
            }
        }
        if (tt) cout << "NO\n"; else cout << "YES\n";
    }
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/