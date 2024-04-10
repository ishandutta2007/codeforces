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

ll n, m, k, j, o, a[500001], r[3], g[3], b[3];
string s,d;
map<ll,ll> t;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n;

    ll l=0,r=0;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    cout << a[n-1] << " ";
    ll x=a[n-1];
    for (int i = n-1; i >= 0; i--)
    {
        if (x%a[i]==0 && !t[a[i]]) {t[a[i]]=1,a[i]=0;}
    }

    for (int i = n-2; i >= 0; i--) if (a[i]) {cout << a[i] << "\n";exit(0);}
    cout << 1;
    return 0;
}
/**/
/*for (int i = 0; i < n; i+=3)
    {
        if (s[i]=='R') r[0]++; else
        if (s[i]=='B') b[0]++; else g[0]++;
    }
    for (int i = 1; i < n; i+=3)
    {
        if (s[i]=='R') r[1]++; else
        if (s[i]=='B') b[1]++; else g[1]++;
    }
    for (int i = 2; i < n; i+=3)
    {
        if (s[i]=='R') r[2]++; else
        if (s[i]=='B') b[2]++; else g[2]++;
    }
    ll ans=0;
    for (int i = 0; i < 3; i++)
    {
        if (r[0]>=g[0] && r[0]>=b[0])
        {
            ans+=g[0]+b[0];
        }else
        if (b[0]>=g[0] && r[0]<=b[0]) ans+=r[0]+g[0]; else
        if (r[0]<=g[0] && r[0]<=g[0]) ans+=b[0]+r[0];
    }
    cout << a[i];*/