#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,bin[1001],d[1001],p[1001];
bool vis[1001];
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>d[i];
            p[i]=i;
            bin[i]=vis[i]=0;
        }
        sort(p+1,p+n+1,[&](int x,int y){return d[x]>d[y];});
        for(int i=1;i<=n;++i)
        {
            int x=p[i];
            if(vis[x])
                continue;
            vis[x]=1;
            while(d[x]--)
            {
                cout<<"? "<<x<<endl;
                int y;
                cin>>y;
                link(x,y);
                if(vis[y])
                    break;
                vis[y]=1;
            }
        }
        cout<<"! ";
        for(int i=1;i<=n;++i)
            cout<<anc(i)<<" ";
        cout<<endl;
    }
    return 0;
}