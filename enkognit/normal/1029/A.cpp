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

ll n,m,k,i,j,a[200001];
string s,l,r,d;
bool t;

int main()
{
 cin >> n >> m;
 cin >> s;
 cout << s;
 ll u=n;
 d=s;
 for (i=0;i<n-1;i++)
 {
  l+=s[i];
  r=s[n-i-1]+r;
  if (l==r) d=s.substr(i+1,n-i-1);
 }
 for (i=0;i<m-1;i++) cout << d;
 return 0;
}