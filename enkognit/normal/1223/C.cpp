#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD=1e9+7;

ll n, m, it, i, p, k, T, j, q[2000001], in[100001], out[100001], B, C, y, kol, d[1000001];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    vector <ll> q;
    while (t--)
    {
        ll n, x, a, y, b, k;
        cin >> n;
        q.clear();
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            x/=100;
            q.pb(x);
        }
        sort(q.begin(),q.end());
        reverse(q.begin(),q.end());
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        if (x>y) swap(x,y), swap(a,b);
        ll l=1, r=n+1;
        while (l<r)
        {
            ll w=(l+r)/2, p1=0, p2=0, p3=0;
            for (int i = 1; i <= w; i++)
            {
                if (i%a==0 && i%b==0) p3++; else
                if (i%a==0 && i%b) p1++; else
                if (i%a && i%b==0) p2++;
            }
            ll sum=0;
            //if (p1+p2+p3>q.size()) {l=n+1;break;}
            for (int i = 0; i < p3; i++) sum+=q[i]*(x+y);
            for (int i = p3; i < p3+p2; i++) sum+=q[i]*y;
            for (int i = p3+p2; i < p3+p2+p1; i++) sum+=q[i]*x;
            if (sum>=k) r=w; else l=w+1;
        }
        if (l==n+1) cout << -1; else cout << l;
        cout << "\n";
    }
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/