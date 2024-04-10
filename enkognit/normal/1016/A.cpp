#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define len length()
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>

using namespace std;

const ll N=1e18;

ll n,m,a[200001];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n >> m;
 ll x=0;
 for (int i=0;i<n;i++) cin >> a[i];
 for (int i=0;i<n;i++) {x+=a[i];cout << x/m << " ";x-=x/m*m;}
 return 0;
}