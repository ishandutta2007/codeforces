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
        for(int i=0;i<n;++i)
            vis[i]=0;
        bool flag=0;
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            if(vis[(i+x%n+n)%n])
                flag=1;
            vis[(i+x%n+n)%n]=1;
        }
        cout<<(flag? "NO":"YES")<<'\n';
    }
    return 0;
}