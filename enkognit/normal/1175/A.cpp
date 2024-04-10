#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, a[300005], ans;
string s, d;
vector <ll> c[300005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    ll t=0;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll o=0, p=1;
        while (n)
        {
           if (n==1) n--,o++;else
            if (n%k) o+=n%k,n-=n%k;
           else o++, n/=k;
        }
        cout << o << "\n";
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/