#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j, a[5000];
pll b[200005];
vector <ll> v, c[300005];
bool z[305];
string s,t,p;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        ll p=k*3/__gcd(k,3ll)+1;
if (k%3)
        {
            if (n%3==0) cout << "Bob\n"; else cout << "Alice\n";
        }else
        if (n<p)
        {
            if (n==p-1 || n%3!=0)cout << "Alice\n"; else cout << "Bob\n";
        }else
        {ll o=n%p;
        if (o%3==0 && o!=p-1) cout << "Bob\n"; else cout << "Alice\n";}
    }
    return 0;
}