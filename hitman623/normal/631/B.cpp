#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
long a[5001][5001]={0};
long n,m,i,j,k,x[100005],y[100005],c[100005],row[5001]={0},col[5001]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(i=0;i<k;++i)
    cin>>x[i]>>y[i]>>c[i];
    for(i=k-1;i>=0;--i)
        if(x[i]==1)
        {
          if(row[y[i]-1]==0)
          {
              row[y[i]-1]=1;
              for(j=0;j<m;++j)
                if(!a[y[i]-1][j])
                a[y[i]-1][j]=c[i];
          }
        }
        else
        {
           if(col[y[i]-1]==0)
           {
               col[y[i]-1]=1;
               for(j=0;j<n;++j)
                if(!a[j][y[i]-1])
                a[j][y[i]-1]=c[i];
           }
        }
    for(i=0;i<n;++i)
    {for(j=0;j<m;++j)
    cout<<a[i][j]<<" ";
    cout<<endl;}
    return 0;
}