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
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, ans, lr[10001], rr[10001], a[500001];vector<ll> b[500001];
string s,d[6],ss;
map<ll,ll> t;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
	for (int j = 0; j < m; j++)
    {
        cin >> lr[j] >> rr[j];
        ll l=lr[j]-1,r=rr[j]-1;
        for (int i = l; i <= r; i++)
        {
            b[i].pb(j);
        }
    }
    ll pos=0,ans=-1;
    for (int u = 0; u < n; u++)
    {
        for (int i = 0; i < b[u].size(); i++)
        {
            for (int j = lr[b[u][i]]-1; j < rr[b[u][i]]; j++)
            {
                a[j]--;
            }
        }
        ll mx=-1e9,mi=1e9;
        for (int i = 0; i < n; i++) mx=max(mx,a[i]),mi=min(mi,a[i]);
        if (mx-mi>ans) ans=mx-mi,pos=u;
        for (int i = 0; i < b[u].size(); i++)
        {
            for (int j = lr[b[u][i]]-1; j < rr[b[u][i]]; j++)
            {
                a[j]++;
            }
        }
    }
    cout << ans << "\n";
    cout << b[pos].size() << "\n";
    for (int i = 0; i < b[pos].size(); i++) cout << b[pos][i]+1 << " ";
    return 0;
}
/**/
/**/