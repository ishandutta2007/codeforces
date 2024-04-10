#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, i, j, m, ans, k, q, l, r, z, a[500001];
ll b[500001];
vector <ll> v;
vector <ll> c[100001];
ll t[100001];
string s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout 
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        if (s[s.size()-1]=='<' || s[0]=='>') cout << "0\n"; else
        {
            ll l=0, r=n-1;
            while (s[l]=='<' && l<n)
            {
                l++;
            }
            while (s[r]=='>' && r>0) r--;
            cout << min(l,n-r-1) << "\n";
        }
    }
    return 0;
}