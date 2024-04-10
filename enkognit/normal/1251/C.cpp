#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, l0[300005], l1[300005], r0[300005], r1[300005];
string s;
string v1, v0;
bool tt[1000001], q[1000001];

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        v0="";
        v1="";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]%2) v1+=s[i]; else v0+=s[i];
        }
        string d="";
        ll l=0, r=0;
        while (r<v1.size() || l<v0.size())
        {
            if (r==v1.size()) d+=v0[l], l++; else
            if (l==v0.size()) d+=v1[r], r++; else
            if (v0[l]<v1[r])
            {
                d+=v0[l];
                l++;
            }else
            if (v0[l]>v1[r])
            {
                d+=v1[r];
                r++;
            }else
            {
                if (v0<v1)
                {
                    while (l<v0.size() && v0[l]==v0[l+1]) d+=v0[l], l++;
                    d+=v0[l],l++;
                }else
                {
                    while (r<v1.size() && v1[r]==v1[r+1]) d+=v1[r], r++;
                    d+=v1[r],r++;
                }
            }
        }
        cout << d << "\n";
    }
    return 0;
}