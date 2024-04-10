#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>

using namespace std;

//ll n, m, i, j, k, l, r, ans, T, Q, K, a[300001], b[100001];
//string s, d;
//vector <ll> c[300001], v;

ll a[400001], b[400001];
ll n, m, i, j;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l=0, r=m-1;
    while (l<r)
    {
        ll w=(l+r)/2;
        bool tt=0;
        for (int i = 1; i <= n; i++) b[i]=a[i];
        b[n]=min(a[n]+w,m-1);
        for (int i = n-1; i > 0; i--)
            if (b[i]<=b[i+1]) b[i]=min(b[i]+w,b[i+1]); else
            {
                if (m-b[i]>w) {tt=1;break;}else
                {
                    ll o=m-b[i];
                    b[i]=min(w-o,b[i+1]);
                }
            }
        //cout << w << ": ";
        //for (int i = 1; i <= n; i++) cout << b[i] << " ";
        //cout << "\n";
        if (tt) l=w+1; else r=w;
    }
    cout << l;
    return 0;
}
/*
10000 10000 2
1 4232
3 1 10000 4231 10000
*/