#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m;
char mp[51][51];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>mp[i][j];
        for(int i=n;i>=1;--i)
            for(int j=1;j<=m;++j)
            {
                if(mp[i][j]!='*')
                    continue;
                int x=i;
                while(x+1<=n&&mp[x+1][j]=='.')
                {
                    mp[x][j]='.';
                    mp[x+1][j]='*';
                    ++x;
                }
            }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
                cout<<mp[i][j];
            cout<<'\n';
        }
    }
    return 0;
}