#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define len length()
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define sp system("pause")

using namespace std;

const ll N=1e18;

ll n,m,k=0,l,x;
pll a[1001];

bool comp(pll i,pll j)
{
 return (i.fi>j.fi || (i.fi==j.fi && i.se<j.se));
}

int main()
{
 //freopen("cows.in","r",stdin);
 //freopen("cows.out","w",stdout);
 cin >> n;
 for (int i=0;i<n;i++) {cin >> m >> k >> l >> x;a[i]=mp(m+k+l+x,i);}
 sort(a,a+n,comp);
 for (int i=0;i<n;i++) if (a[i].se==0) {cout << i+1;exit(0);}
 return 0;
}