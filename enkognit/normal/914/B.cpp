#include <bits/stdc++.h>
#define len length()
#define pb push_back
#define pu push
#define fi first
#define se second
#define ll long long

using namespace std;

int n,m,i,j,k=0,a[100001],l[100001];
int u[300001];
string s;

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (i=1;i<=n;i++)
 {
  cin >> a[i];
  if (l[a[i]]==0) m++,u[m]=a[i];
  l[a[i]]++;
  if (a[i]>k) k=a[i];
 }
 sort(u+1,u+m+1);
 reverse(u+1,u+m+1);
 for (i=1;i<=m;i++)
  if (l[u[i]]%2==1) cout << "Conan",exit(0);
 cout << "Agasa";
 return 0;
}