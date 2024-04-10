#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ans,minn;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        minn=4;
        ans=-1;
        if(n<10)
        {
            cout<<"7\n";
            continue;
        }
        if(n<100)
        {
            for(int i=10;i<100;++i)
                if(i%7==0)
                {
                    int cnt=(i%10!=n%10)+(i/10!=n/10);
                    if(cnt<minn)
                    {
                        minn=cnt;
                        ans=i;
                    }
                }
            cout<<ans<<'\n';
            continue;
        }
        for(int i=100;i<1000;++i)
            if(i%7==0)
            {
                int cnt=(i%10!=n%10)+(i/10%10!=n/10%10)+(i/100!=n/100);
                if(cnt<minn)
                {
                    minn=cnt;
                    ans=i;
                }
            }
        cout<<ans<<'\n';
    }
    return 0;
}