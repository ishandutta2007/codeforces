#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[101];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        int ans=0;
        for(int d=-200;d<=200;++d)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                {
                    int sum=1,val=a[i];
                    for(int k=i-j;k>=1;k-=j)
                    {
                        sum+=((val-=d)==a[k]);
                        if(val<-200||val>200)
                            break;
                    }
                    val=a[i];
                    for(int k=i+j;k<=n;k+=j)
                    {
                        sum+=((val+=d)==a[k]);
                        if(val<-200||val>200)
                            break;
                    }
                    ans=max(ans,sum);
                }
        cout<<n-ans<<'\n';
    }
    return 0;
}