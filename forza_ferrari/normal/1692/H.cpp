#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,a[200001],node[200001],cnt,l,r,val,ans;
vector<int> v[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        l=r=val=cnt=0;
        ans=-1e9;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            node[i]=a[i];
        }
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(int i=1;i<=cnt;++i)
            v[i].clear();
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            v[a[i]].emplace_back(i);
        }
        for(int i=1;i<=cnt;++i)
        {
            int maxn=-1e9,pos=0,tag=0,lst=0;
            for(auto j:v[i])
            {
                if(lst)
                    tag-=j-lst-1;
                if(-tag>maxn)
                {
                    maxn=-tag;
                    pos=j;
                }
                ++tag;
                if(maxn+tag>ans)
                {
                    ans=maxn+tag;
                    l=pos,r=j;
                    val=node[i];
                }
                lst=j;
            }
        }
        //cout<<ans<<'\n';
        cout<<val<<" "<<l<<" "<<r<<'\n';
    }
    return 0;
}