#include <bits/stdc++.h>
#include <iostream>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

const ll N=200001;

ll x[100001],y[100001],a[100001];ll d[400001],n,m,i,j,k,l;


int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  cout << m/n+(m%n>0);
  return 0;
}