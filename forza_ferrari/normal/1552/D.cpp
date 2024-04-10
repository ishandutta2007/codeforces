#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[11];
int main()
{
    cin>>t;
    while(t--)
    {
        bool flag=0;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            flag|=a[i]==0;
        }
        if(flag)
        {
            cout<<"Yes\n";
            continue;
        }
        for(int s=1;s<1<<n;++s)
        {
            for(int t=s;;t=s&(t-1))
            {
                int sum=0;
                for(int i=1;i<=n;++i)
                    if(s&(1<<(i-1)))
                    {
                        if(t&(1<<(i-1)))
                            sum+=a[i];
                        else
                            sum-=a[i];
                    }
                if(!sum)
                {
                    flag=1;
                    break;
                }
                if(t==0)
                    break;
            }
            if(flag)
                break;
        }
        cout<<(flag? "Yes":"No")<<'\n';
    }
    return 0;
}