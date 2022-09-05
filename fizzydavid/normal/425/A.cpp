#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
int n,k,a[222],b[222],sum=-(1<<28),ans=-2000000000;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int q=n;q>=1;q--)
    {
        for(int i=1;i<=n-q+1;i++)
        {
            int j=i+q-1;
//          cout<<"i="<<i<<" j="<<j<<endl;
            for(int t=1;t<=n;t++)
            {
                b[t]=a[t];
            }
            for(int t=1;t<=k;t++)
            {
                int mn=1<<28,mni=0,mx=-1<<28,mxi=0;
                for(int p=i;p<=j;p++)if(b[p]<mn)mn=b[p],mni=p;
                for(int p=1;p<i;p++)if(b[p]>mx)mx=b[p],mxi=p;
                for(int p=j+1;p<=n;p++)if(b[p]>mx)mx=b[p],mxi=p;
//              cout<<"mxi="<<mxi<<" mni="<<mni<<endl;
                if(mxi!=0&&mni!=0)swap(b[mxi],b[mni]);
            }
//          for(int t=1;t<=n;t++)cout<<b[t]<<" ";
//          cout<<endl;
            int mn=1<<28,mni=0,mx=-1<<28,mxi=0;
            for(int p=i;p<=j;p++)
            {
                if(b[p]<mn)mn=b[p],mni=p;
            }               
            for(int p=1;p<i;p++)
            {
                if(b[p]>mx)mx=b[p],mxi=p;
            }               
            for(int p=j+1;p<=n;p++)         
            {
                if(b[p]>mx)mx=b[p],mxi=p;
            }
//          cout<<"mx="<<mx<<" mn="<<mn<<endl;
                int s=0;
                for(int p=i;p<=j;p++)s+=b[p];
                sum=max(s,sum);
        }
    }
    cout<<sum;
//  system("pause");
    return 0;
}