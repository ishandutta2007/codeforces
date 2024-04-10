#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,q;
string a[100],b[100];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i;
    cin>>n>>m;
    for(i=0;i<n;i++)
      cin>>a[i];
    for(i=0;i<m;i++)
      cin>>b[i];
    cin>>q;
    while(q--)
      {
       cin>>i;
       cout<<a[(i-1)%n]<<b[(i-1)%m]<<"\n";
      }
    return 0;
}