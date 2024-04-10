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

ll n,m,k,l,b,x,y,w,a[1001];
bool t[1001];

void rec(ll k,bool* t)
{
 if (t[k]) cout << k << " ";else {t[k]=1;rec(a[k],t);t[k]=0;}
}

int main()
{
 //freopen("cows.in","r",stdin);
 //freopen("cows.out","w",stdout);
 cin >> n;
 for (int i=1;i<=n;i++) cin >> a[i];
 for (int i=1;i<=n;i++) rec(i,t);
 return 0;
}