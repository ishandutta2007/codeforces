#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define pi 3.14159265358979323846

using namespace std;

const ll mod=1e9+7;

ll n, m, j, ans, T, xx, yy, o, l, k, r;
string s, d;
vector <pll> v[50];

int main()
{
	//freopen("egroup.in", "r", stdin);
	//freopen("egroup.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    cin >> m;
    for (int j = 'a'; j <= 'z'; j++)
    {
        ll k=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]==j)
            {
                if (s[i-1]!=j)
                {
                    if (k && l) v[j-'a'].pb(mp(k,l));
                    k=0,l=0;
                }
                k++;
            }
             else
            {
                l++;
            }
        }
        if (k) v[j-'a'].pb(mp(k,l));
    }
    for (int it = 0; it < m; it++)
    {
        ll x, c;
        char ch;
        cin >> x >> ch;
        c=ch-'a';
        ll p=0, z=0, k=0, ans=x;
        if (v[c].size()) k=v[c][0].fi;
        for (int i = 0; i < v[c].size(); i++)
        {
            if (i)
            {
                z-=v[c][i-1].se;
                k-=v[c][i-1].fi;
            }
            if (i>p)
            {
                k=v[c][i].fi;
                z=0;
                p=i;
            }
            while (p+1<v[c].size() && z+v[c][p].se<=x) p++,z+=v[c][p-1].se,k+=v[c][p].fi;
            ans=max(ans,min(n,k+x));
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
4 3
1 2 3 4
1 2
2 3
3 4
*/