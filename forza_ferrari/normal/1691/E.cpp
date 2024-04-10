#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct element
{
    int l,r,c;
    bool operator <(element &other) const
    {
        return r<other.r;
    }
}a[100001];
int t,n,bin[100001],ans;
pair<int,int> val[100001];
multiset<pair<int,int> > s1,s2;
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
    {
        bin[y]=x;
        val[x].first=max(val[x].first,val[y].first);
        val[x].second=max(val[x].second,val[y].second);
        --ans;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].c>>a[i].l>>a[i].r;
            bin[i]=0;
        }
        ans=n;
        sort(a+1,a+n+1);
        s1.clear();
        s2.clear();
        for(int i=1;i<=n;++i)
        {
            if(a[i].c==1)
            {
                val[i]={-1,a[i].r};
                for(auto it=s1.lower_bound({a[i].l,0});it!=s1.end();it=s1.erase(it))
                {
                    int w=val[it->second].second;
                    s2.erase({w,it->second});
                    link(i,it->second);
                }
            }
            else
            {
                val[i]={a[i].r,-1};
                for(auto it=s2.lower_bound({a[i].l,0});it!=s2.end();it=s2.erase(it))
                {
                    int w=val[it->second].first;
                    s1.erase({w,it->second});
                    link(i,it->second);
                }
            }
            s1.emplace(val[i].first,i);
            s2.emplace(val[i].second,i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}