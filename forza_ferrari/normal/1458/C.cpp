#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,m,node[1001][1001][3],ans[1001][1001],pos[3],d[3];
int main()
{
    cin>>t;
    while(t--)
    {
        pos[0]=0;
        pos[1]=1;
        pos[2]=2;
        d[0]=d[1]=d[2]=0;
        cin>>n>>m;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                node[i][j][0]=i,node[i][j][1]=j;
                cin>>node[i][j][2];
                --node[i][j][2];
            }
        while(m--)
        {
            char c;
            cin>>c;
            if(c=='L')
                d[pos[1]]=(d[pos[1]]+n-1)%n;
            if(c=='R')
                d[pos[1]]=(d[pos[1]]+1)%n;
            if(c=='U')
                d[pos[0]]=(d[pos[0]]+n-1)%n;
            if(c=='D')
                d[pos[0]]=(d[pos[0]]+1)%n;
            if(c=='I')
                pos[1]^=pos[2]^=pos[1]^=pos[2];
            if(c=='C')
                pos[0]^=pos[2]^=pos[0]^=pos[2];
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                ans[(node[i][j][pos[0]]+d[pos[0]])%n][(node[i][j][pos[1]]+d[pos[1]])%n]=(node[i][j][pos[2]]+d[pos[2]])%n+1;
        for(int i=0;i<n;++i,cout<<endl)
            for(int j=0;j<n;++j)
                cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}