#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
const double eps=1e-12;
int n,m,q,p[200001],w[200001],cnt[200001];
double ans;
struct cmp
{
    bool operator ()(const pair<double,int> &x,const pair<double,int> &y) const
    {
        return fabs(x.first-y.first)>eps? x.first<y.first:x.second<y.second;
    }
};
multiset<pair<double,int>,cmp> s1,s2;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int k)
{
    if(cnt[k]<w[k])
        s1.emplace(p[k]*(1.*(cnt[k]+1)/(cnt[k]+1+w[k])-1.*cnt[k]/(cnt[k]+w[k])),k);
    if(cnt[k])
        s2.emplace(p[k]*(1.*cnt[k]/(cnt[k]+w[k])-1.*(cnt[k]-1)/(cnt[k]-1+w[k])),k);
}
inline void del(int k)
{
    if(cnt[k]<w[k])
        s1.erase(s1.find({p[k]*(1.*(cnt[k]+1)/(cnt[k]+1+w[k])-1.*cnt[k]/(cnt[k]+w[k])),k}));
    if(cnt[k])
        s2.erase(s2.find({p[k]*(1.*cnt[k]/(cnt[k]+w[k])-1.*(cnt[k]-1)/(cnt[k]-1+w[k])),k}));
}
int main()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;++i)
        p[i]=read();
    for(int i=1;i<=n;++i)
    {
        w[i]=read();
        s1.emplace(1.*p[i]/(1+w[i]),i);
    }
    while(!s1.empty())
    {
        if(!m)
            break;
        --m;
        ans+=(--s1.end())->first;
        int k=(--s1.end())->second;
        del(k);
        ++cnt[k];
        add(k);
    }
    while(q--)
    {
        int val=read()==1? 1:-1,k=read();
        if(val==1)
        {
            ans-=1.*p[k]*cnt[k]/(cnt[k]+w[k]);
            del(k);
            ++w[k];
            add(k);
            ans+=1.*p[k]*cnt[k]/(cnt[k]+w[k]);
            while(!s1.empty())
            {
                if(!m)
                    break;
                --m;
                ans+=(--s1.end())->first;
                int x=(--s1.end())->second;
                del(x);
                ++cnt[x];
                add(x);
            }
            while(!s1.empty()&&!s2.empty())
            {
                if(s2.begin()->second==(--s1.end())->second||s2.begin()->first>(--s1.end())->first)
                    break;
                ans+=(--s1.end())->first-s2.begin()->first;
                int x=(--s1.end())->second,y=s2.begin()->second;
                del(x);
                del(y);
                ++cnt[x];
                --cnt[y];
                add(x);
                add(y);
                break;
            }
        }
        else
        {
            ans-=1.*p[k]*cnt[k]/(cnt[k]+w[k]);
            del(k);
            if(cnt[k]==w[k])
            {
                ++m;
                --cnt[k];
            }
            --w[k];
            add(k);
            ans+=1.*p[k]*cnt[k]/(cnt[k]+w[k]);
            while(!s1.empty())
            {
                if(!m)
                    break;
                --m;
                ans+=(--s1.end())->first;
                int x=(--s1.end())->second;
                del(x);
                ++cnt[x];
                add(x);
            }
            while(!s1.empty()&&!s2.empty())
            {
                if(s2.begin()->second==(--s1.end())->second||s2.begin()->first>(--s1.end())->first)
                    break;
                ans+=(--s1.end())->first-s2.begin()->first;
                int x=(--s1.end())->second,y=s2.begin()->second;
                del(x);
                del(y);
                ++cnt[x];
                --cnt[y];
                add(x);
                add(y);
                break;
            }
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}