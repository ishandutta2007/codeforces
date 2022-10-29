#include <bits/stdc++.h>

#define fr front
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pu push
#define mp make_pair
#define pll pair<ll,ll>

using namespace std;

ll n,m,k,l;

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n >> m >> k >> l;
  cout << min(n*l,min((m-n%m)*k,(n%m)*l));
  return 0;
}