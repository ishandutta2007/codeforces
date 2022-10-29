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
        cin >> s;
        cin >> t;
        cin >> p;
        for (int i = 0; i < 27; i++) a[i]=0;
        for (int i = 0; i < t.size(); i++) z[i]=0;
        for (int i = 0; i < p.size(); i++) a[p[i]-'a']++;
        ll l=0;
        for (int i = 0; i < t.size(); i++)
        {
            if (l<s.size() && t[i]==s[l]) l++,z[i]=1;
        }
        bool tt=1;
        for (int i = 0; i < t.size(); i++)
            if (!z[i])
            {
                if (a[t[i]-'a']==0) tt=0;  else a[t[i]-'a']--;
            }
        if (l<s.size() || tt==0) cout << "NO\n"; else cout << "YES\n";
    }
    return 0;
}