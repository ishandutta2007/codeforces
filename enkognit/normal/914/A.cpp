#include <bits/stdc++.h>
#define len length()
#define pb push_back
#define pu push
#define fi first
#define se second
#define ll long long

using namespace std;

int n,m,i,j,k=-1000000,l;
string s;

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (i=1;i<=n;i++)
 {
  cin >> l;
  if (l>k)
   if ((double)sqrt(l)!=(int)sqrt(l)) k=l;
 }
 cout << k << "\n";
     return 0;
}