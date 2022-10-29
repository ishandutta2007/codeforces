#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, dp[300001], a[300001], pref[300001];string s;
vector <ll> v, ans;

bool lo(ll h)
{
    while (h%2==0) h/=2;
    return (h==1);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < 40; i++)
    {
        if (lo(n+1))
        {
            cout << v.size()*2 << "\n";
            for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
            exit(0);
        }
        if (n%2==0) v.pb(0); else
        {
            ll r=0, h=n, j=0;
            while (h)
            {
                j++;
                if (h%2==0) r=j;
                h/=2;
            }
            n^=((ll)pow(2,r)-1);
            v.pb(r);
        }
        n++;
    }
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/