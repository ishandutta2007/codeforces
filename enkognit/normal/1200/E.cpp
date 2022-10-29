#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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

ll n, m, k, q, p, ans, l, r, i, j, x, y, a[500001], b[11][11][11];
vector <ll> c[300001];
vector <ll> v;
ll pr[2000001];
bool t[1000001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    string ans, p="";
    cin >> ans;
    for (int it = 1; it < n; it++)
    {
        cin >> s;
        if (ans.size()<s.size()) p=s+"#"+ans; else
        {
            //cout << 1;
            p=s+"#";
            for (int j = ans.size()-s.size(); j < ans.size(); j++) p+=ans[j];
        }
        for (int i = 0; i < p.size(); i++) pr[i]=0;
        //cout << p << "\n";
        for (int i = 1; i < p.size(); i++)
        {
            //cout << pr[i-1] << "\n";
            ll j=pr[i-1];
            while (p[i]!=p[j] && j>0) j=pr[j-1];
            if (p[i]==p[j]) j++;
            pr[i]=j;
        }
        for (int i = pr[p.size()-1]; i < s.size(); i++)ans+=s[i];
        //cout << ans << "\n";
     }
     cout << ans;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/