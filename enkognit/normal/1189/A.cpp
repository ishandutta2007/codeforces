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

ll n, m, k, l, r, i, j, k1, k0;
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) k1+=(s[i]=='1'), k0+=(s[i]=='0');
    if (k1==k0)
    {
        cout << "2\n";
        cout << s[0] << "\n";
        s.erase(s.begin());
        cout << s << "\n";
    }else
    cout << "1\n" << s << "\n";
    return 0;
}