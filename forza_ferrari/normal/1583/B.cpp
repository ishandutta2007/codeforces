#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m;
bool vis[100001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(register int i=1;i<=n;++i)
            vis[i]=0;
        for(register int i=1;i<=m;++i)
        {
            int a,b,c;
            cin>>a>>b>>c;
            vis[b]=1;
        }
        for(register int i=1;i<=n;++i)
            if(!vis[i])
            {
                for(register int j=1;j<=n;++j)
                    if(j!=i)
                        cout<<i<<" "<<j<<endl;
                break;
            }
    }
    return 0;
}