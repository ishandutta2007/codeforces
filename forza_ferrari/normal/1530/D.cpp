#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[200001],b[200001],ans;
bool vis[200001];
vector<int> v;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            vis[i]=0;
        v.clear();
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(!vis[a[i]])
            {
                vis[a[i]]=1;
                b[i]=a[i];
                ++ans;
            }
            else
                v.emplace_back(i);
        }
        int p=1;
        for(auto i:v)
        {
            while(p<=n&&vis[p])
                ++p;
            b[i]=p++;
        }
        v.clear();
        for(int i=1;i<=n;++i)
            if(b[i]==i)
                v.emplace_back(i);
        if(v.size()>1)
        {
            for(int i=1;i<(int)v.size();++i)
                b[v[i]]=v[i-1];
            b[v[0]]=v.back();
        }
        else if(v.size()==1)
        {
            bool flag=0;
            for(int i=1;i<=n;++i)
                if(i!=v[0]&&a[i]!=b[i])
                {
                    swap(b[i],b[v[0]]);
                    flag=1;
                    break;
                }
            if(!flag)
            {
                b[v[0]]=a[v[0]];
                for(int i=1;i<=n;++i)
                    if(i!=v[0]&&b[i]==b[v[0]])
                    {
                        b[i]=v[0];
                        break;
                    }
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;++i)
            cout<<b[i]<<' ';
        cout<<'\n';
    }
    return 0;
}