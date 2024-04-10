#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,x[5001],y[5001];
bool vis[5001];
inline long long dis(int a1,int b1,int a2,int b2)
{
    return 1ll*(a1-a2)*(a1-a2)+1ll*(b1-b2)*(b1-b2);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    cout<<"1 ";
    vis[1]=1;
    int lst=1;
    for(int i=1;i<n;++i)
    {
        long long maxn=0,now=0;
        for(int j=1;j<=n;++j)
            if(!vis[j]&&dis(x[lst],y[lst],x[j],y[j])>maxn)
            {
                maxn=dis(x[lst],y[lst],x[j],y[j]);
                now=j;
            }
        cout<<now<<" ";
        vis[now]=1;
        lst=now;
    }
    cout<<'\n';
    return 0;
}