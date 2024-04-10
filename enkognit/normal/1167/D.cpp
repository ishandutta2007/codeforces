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

ll n, m, w, l, r, T, k, sum, a[500001];
ll d[1000001];

string s;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    s=' '+s;
    ll o=0, k=0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i]=='(')
        {
            k++;
            a[i]=k;
        }else
        {
            a[i]=k;
            k--;
        }
        //a[i]=k;
        //cout << a[i] << " ";
        o=max(k,o);
    }
//cout << "\n";
    for (int i = 1; i <= n; i++) if (a[i]>o/2) cout << 1; else cout << 0;
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