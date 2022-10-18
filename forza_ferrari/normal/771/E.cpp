#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;
#define int long long
int t,n,m,sum,ans[300001];
vector<pair<int,int> > v1[300001],v2[300001];
struct element
{
    int head,tail,q[300001],pos,sum[300001],val[300001],fa[300001],tag[300001],res;
    vector<int> v[300001];
    unordered_map<int,int> mp;
    inline void init()
    {
        for(int i=1;i<=n;++i)
        {
            q[i]=i;
            sum[i]+=sum[i-1];
        }
        mp[0]=0;
        v[0].emplace_back(0);
    }
    inline int calc(int x)
    {
        return val[x]+tag[fa[x]];
    }
    inline int merge(int x,int y)
    {
        if(v[x].size()<v[y].size())
            swap(x,y);
        for(int i:v[y])
        {
            val[i]+=tag[y]-tag[x];
            v[fa[i]=x].emplace_back(i);
        }
        tag[y]=0;
        v[y].clear();
        v[y].shrink_to_fit();
        return x;
    }
    inline void insert(int k,bool opt)
    {
        tail=mp.count(sum[k])? mp[sum[k]]:-1;
        mp[sum[k]]=k;
        if(opt)
        {
            while(head<=tail)
                q[k]=merge(q[k],q[head++]);
            ++tag[q[k]];
            res+=v[q[k]].size();
        }
    }
    inline void find(int k)
    {
        int l=0,r=k-1,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(calc(mid)<calc(k-1))
                l=mid+1;
            else
            {
                pos=mid;
                r=mid-1;
            }
        }
    }
    inline void solve(int k,element &a,element &b,bool opt)
    {
        if(opt)
        {
            val[k]=b.val[k]-tag[q[a.pos]];
            fa[k]=q[a.pos];
            v[q[a.pos]].emplace_back(k);
        }
        else
        {
            val[k]=max(max(a.calc(k-1)+(a.pos<=b.tail),b.calc(k-1)+(b.pos<=a.tail)),tail==-1? 0:val[tail]+1);
            if(a.calc(k-1)<val[k])
                a.pos=k;
            if(b.calc(k-1)<val[k])
                b.pos=k;
        }
    }
}s1,s2,s3;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
signed main()
{
    n=read(),m=1;
    for(int i=1;i<=n;++i)
        s3.sum[i]=s1.sum[i]=read();
    for(int i=1;i<=n;++i)
        s3.sum[i]+=s2.sum[i]=read();
    s1.init();
    s2.init();
    s3.init();
    v1[n].emplace_back(n,1);
    for(int i=1;i<=n;++i)
    {
        s3.insert(i,0);
        s1.insert(i,1);
        s2.insert(i,1);
        s1.find(i);
        s2.find(i);
        s3.solve(i,s1,s2,0);
        s1.solve(i,s2,s3,1);
        s2.solve(i,s1,s3,1);
        sum+=s1.res+s2.res+s3.val[i];
        s1.res+=s3.val[i];
        s2.res+=s3.val[i];
        for(auto j:v1[i])
            ans[j.second]=s1.calc(j.first);
        for(auto j:v2[i])
            ans[j.second]=s2.calc(j.first);
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}