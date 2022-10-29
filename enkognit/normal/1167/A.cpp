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

const ll MOD=998244353;

ll n, m, w, l, r, ans, k, sum, a[300001], b[300001];
vector <ll> c;
bool t[1000001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s;
        cin >> n;
        cin >> s;
        if (n<11) {cout << "NO\n";continue;}
        bool tt=0;
        for (int i = 0; i <= n-11; i++)
            if (s[i]=='8') tt=1;
        if (tt) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/