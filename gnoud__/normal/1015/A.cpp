#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[1000];
int main()
{
  int n,m;
cin>>n>>m;
forinc(i,1,n)
{int l,r;cin>>l>>r;for(int j=l;j<=r;++j) a[j]=1;}int dem=0;
forinc(i,1,m) if(!a[i]) dem++;
cout<<dem<<endl;
forinc(i,1,m) if(!a[i]) cout<<i<<" ";
}