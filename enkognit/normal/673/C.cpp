#include <bits/stdc++.h>

using namespace std;

int a[5001],c[5001],d[5001];

int main()
{
    int n,i,j;
    cin >> n;
    d[0]=10000;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for (i=1; i<=n; i++)
    {
     int b[5001]={},m=0,maxi=0;
     for (j=i;j<=n;j++)
     {
      b[a[j]]++;
      if (a[j]>=m)
       {if (b[a[j]]>maxi) {maxi=b[a[j]];m=a[j];}} else
      if (a[j]<m)
       {if (b[a[j]]>=maxi) {maxi=b[a[j]];m=a[j];}}
      c[m]++;
     }
    }
    for (int i=1; i<=n; i++) cout << c[i] << " ";

    /*int a[11];
    int f[11],c;
    for (i=0;i<11;i++) {
        c++;
        if (f[i]!=c) {
            a[i]=0;
            f[i]=c;
        }
        a[i]++;
    }*/

}