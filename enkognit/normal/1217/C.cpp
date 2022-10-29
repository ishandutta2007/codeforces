#include <bits/stdc++.h>
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
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, k, l, m, r, i, j, x, y, ans, a[1000001];
pll b[200001];
bool tt[1000001];
string s;



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ll u=0, ans=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]=='0')
            {
                u++;
            }else
            {
                ll p=0;
                for (int j = i; j < s.size(); j++)
                {
                    p*=2;
                    p+=s[j]-48;
                    //cout << p << " " << i  << "\n";
                    if (j-p+1<i-u) break;else {ans++;}
                }
                u=0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/