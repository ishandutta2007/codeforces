#include<iostream>
#include<cstdio>
using namespace std;
int t,n,cnt[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cnt[i]=0;
        bool flag=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(++cnt[x]>=3)
            {
                if(!flag)
                    cout<<x<<'\n';
                flag=1;
            }
        }
        if(!flag)
            cout<<"-1\n";
    }
    return 0;
}