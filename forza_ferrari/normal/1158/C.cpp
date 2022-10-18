#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,p[500001],nxt[500001],sum;
vector<int> v[500005];
bool flag;
inline void dfs(int l,int r,int val)
{
    if(l>r)
        return;
    if(nxt[r]^(r+1))
    {
        flag=0;
        return;
    }
    if(l==r)
    {
        if(v[l].size())
            flag=0;
        p[l]=val;
        return;
    }
    int lst=l-1;
    for(auto i:v[r+1])
    {
        if(i<l)
        {
            flag=0;
            return;
        }
        if(!v[i].empty()&&v[i][0]<=lst)
        {
            flag=0;
            return;
        }
        p[i]=val;
        dfs(lst+1,i-1,val-1);
        val-=i-lst;
        lst=i;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        flag=1;
        for(int i=2;i<=n+1;++i)
            v[i].clear();
        for(int i=1;i<=n;++i)
        {
            cin>>nxt[i];
            if(nxt[i]==-1)
                nxt[i]=i+1;
            v[nxt[i]].emplace_back(i);
        }
        dfs(1,n,n);
        if(!flag)
            cout<<"-1";
        else
            for(int i=1;i<=n;++i)
                cout<<p[i]<<" ";
        cout<<'\n';
    }
    return 0;
}