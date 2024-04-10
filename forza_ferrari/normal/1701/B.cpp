#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
bool vis[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"2\n";
        for(int i=1;i<=n;++i)
            vis[i]=0;
        for(int i=1;i<=n;++i)
            if(!vis[i])
                for(int j=i;j<=n;j<<=1)
                {
                    vis[j]=1;
                    cout<<j<<" ";
                }
        cout<<'\n';
    }
    return 0;
}