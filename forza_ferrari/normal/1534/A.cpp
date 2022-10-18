#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int flag=2;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                if(c=='R')
                {
                    if(flag==2)
                        flag=((i+j)&1);
                    else
                        if(flag!=((i+j)&1))
                            flag=-1;
                }
                if(c=='W')
                {
                    if(flag==2)
                        flag=((i+j)&1^1);
                    else
                        if(flag!=((i+j)&1^1))
                            flag=-1;
                }
            }
        if(flag==-1)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(flag==2)
            flag=0;
        for(int i=1;i<=n;++i,cout<<endl)
            for(int j=1;j<=m;++j)
                if(((i+j)&1)==flag)
                    cout<<'R';
                else
                    cout<<'W';
    }
    return 0;
}