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

ll n, m, k, j, o, l, r, x, y, xf, yf, kr, kl, ku, kd, kx, ky;
ll a[500001];
string s, d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y;
    cin >> xf >> yf;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='R') kr++, kx++;
        if (s[i]=='L') kl++, kx--;
        if (s[i]=='U') ku++, ky++;
        if (s[i]=='D') kd++, ky--;
    }
    ll kx1=0, ky1=0, o=1e15;
    for (int i = 0; i <= n; i++)
    {
        ll xr=xf-x-kx1, yr=yf-y-ky1;
        ll l=0, r=1e12;
        while (l<r)
        {
            ll w=(l+r)/2;
            ll k=w*n+i, xe=xr-kx*w, ye=yr-ky*w;
            if (abs(xe)>k) {l=w+1;continue;}
            k-=abs(xe);
            xe=0;
            if (abs(ye)>k) l=w+1; else r=w;
        }
        ll k=l*n+i, xe=xr-kx*l, ye=yr-ky*l;
        if (xe<=k)
        {
            k-=abs(xe);
            xe=0;
            if (abs(ye)<=k) o=min(o,l*n+i);
        }
        if (i==n) break;
        if (s[i]=='R') kx1++;
        if (s[i]=='L') kx1--;
        if (s[i]=='U') ky1++;
        if (s[i]=='D') ky1--;
    }
    if (o==1e15) cout << -1; else cout << o;
    return 0;
}