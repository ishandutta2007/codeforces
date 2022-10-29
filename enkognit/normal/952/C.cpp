#include <bits/stdc++.h>

#define ll long long
#define pb push_back()

using namespace std;

//int a[5001],c[5001],d[5001];

ll n,m,i,j,k,l;
vector <ll> a(11);
string s;

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   cin >> n;
   for (i=1;i<=n;i++) {cin >> a[i];}
   k=n;
   for (int u=1;u<n;u++)
   {
    l=a[1];int z=1;
    for (i=2;i<=k;i++)
    {
     if (abs(a[i-1]-a[i])>1) {cout << "NO";exit(0);}
     if (l<a[i]) {l=a[i];z=i;}
    }
    a.erase(a.begin()+z);
    k--;
   }
   cout << "YES";
   return 0;
}