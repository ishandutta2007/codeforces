#include<iostream>
#include<cstdio>
using namespace std;
int t,n,cnt[2];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt[0]=cnt[1]=0;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            if(c=='W')
            {
                if((!cnt[0]||!cnt[1])&&cnt[0]+cnt[1])
                    flag=0;
                cnt[0]=cnt[1]=0;
            }
            else if(c=='R')
                ++cnt[0];
            else
                ++cnt[1];
        }
        if((!cnt[0]||!cnt[1])&&cnt[0]+cnt[1])
            flag=0;
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}