#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200001],cnt[31],g;
int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=30;++i)
            cnt[i]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            for(int j=0;j<=30;++j)
                cnt[j]+=(a[i]>>j)&1;
        }
        g=-1;
        for(int i=0;i<=30;++i)
            if(cnt[i])
            {
                if(g==-1)
                    g=cnt[i];
                else
                    g=gcd(g,cnt[i]);
            }
        if(g==-1)
        {
            for(int i=1;i<=n;++i)
                cout<<i<<" ";
            cout<<endl;
        }
        else
        {
            for(int i=1;i<=g;++i)
                if(g%i==0)
                    cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}