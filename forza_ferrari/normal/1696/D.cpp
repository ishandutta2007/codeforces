#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[250001],pos[250001],ans;
bool vis[250001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        int l=1,r=n,p=1;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            vis[i]=0;
            pos[a[i]]=i;
        }
        vis[a[1]]=1;
        while(p<n)
        {
            while(l<r&&vis[l])
                ++l;
            while(l<r&&vis[r])
                --r;
            int res=p;
            if(l>a[p])
                res=pos[r];
            else if(r<a[p])
                res=pos[l];
            else
            {
                int maxn=a[p],minn=a[p],tmp=p;
                while(tmp<n)
                {
                    ++tmp;
                    maxn=max(maxn,a[tmp]);
                    minn=min(minn,a[tmp]);
                    if(maxn!=a[p]&&minn!=a[p])
                        break;
                    if(maxn==a[tmp]||minn==a[tmp])
                        res=tmp;
                }
                p=res;
            }
            for(int i=p+1;i<=res;++i)
                vis[a[i]]=1;
            p=res;
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}