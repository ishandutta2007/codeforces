#include <bits/stdc++.h>
#define fr front
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define pu push
#define len length()

using namespace std;

ll n,m,k,i,j,l,a[200001];

int main()
{
 cin >> n;
 cin >> m;
 k=1;j=m;l=1;
 for (i=1;i<n;i++)
 {
  cin >> m;
  if (m<=j*2) {k++;if (k>l) l=k;} else k=1;j=m;
 }
 cout << l;
 return 0;
}