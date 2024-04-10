#include<bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005];main(){cin>>n;for(int i=1;i<=n;i++)cin>>a[i];for(int i=2;i<=n;i++){if(a[i]<a[1])c[i-1]++;for(int j=1,k;j<=i-2;j=k+1){k=(i-2)/((i-2)/j);if(a[i]<a[(i-2)/j+1])c[j]++,c[k+1]--;}}for(int i=1;i<n;i++)c[i]+=c[i-1],cout<<c[i]<<' ';}