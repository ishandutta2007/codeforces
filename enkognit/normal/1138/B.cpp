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

ll n, m, j, o, l, r, x, y, ans=0, k00, k10, k11, k01;
string s, d;
vector <ll> v;
ll a[100001];
ll dp[1001][1001];

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    cin >> d;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='0' && d[i]=='0') k00++; else
        if (s[i]=='1' && d[i]=='0') k10++; else
        if (s[i]=='1' && d[i]=='1') k11++; else
        if (s[i]=='0' && d[i]=='1') k01++;
    }
    for (int i = 0; i <= k10; i++)
        for (int j = 0; j <= k11; j++)
        {
            if (i+j>n/2) continue;
            ll p=k11-j;
            if (p+k10-i>n/2 || p>i+j) continue;
            ll u=k01;
            if (u<i+j-p) continue;
            u-=i+j-p;
            p=i+j;
            if (u>n/2-i-j) continue;
            ll z=n/2-i-j-u;
            if (i+j+u+z!=n/2 || z>k00) continue;
            ll x11=0,x00=0,x10=0,x01=0;
            for (int e = 0; e < n; e++)
            {
                if (s[e]=='0' && d[e]=='0' && x00<z) x00++,v.pb(e+1); else
                if (s[e]=='1' && d[e]=='0' && x10<i) x10++,v.pb(e+1); else
                if (s[e]=='1' && d[e]=='1' && x11<j) x11++,v.pb(e+1); else
                if (s[e]=='0' && d[e]=='1' && x01<u) x01++,v.pb(e+1);
            }
            //cout << z << " " << i << " " << j << " " << u << "\n";
            for (int y = 0; y < v.size(); y++) cout << v[y] << " ";
            exit(0);
        }
    cout << -1;
    return 0;
}