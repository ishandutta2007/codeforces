#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
inline int gcd(int x,int y)
{
    if(!x||!y)
        return x|y;
    return x%y? gcd(y,x%y):y;
}
struct num
{
    int a,b;
    num()
    {
        a=b=0;
    }
    num(int a_):
        a(a_),b(1){}
    num(int a_,int b_)
    {
        a=a_;
        b=b_;
        if(b<0)
        {
            a=-a;
            b=-b;
        }
    }
    bool operator <(const num &other) const
    {
        return a*other.b<other.a*b;
    }
    bool operator ==(const num &other) const
    {
        return a*other.b==other.a*b;
    }
    num operator +(const num &other) const
    {
        int x=a*other.b+other.a*b,y=b*other.b,g=gcd(x,y);
        return num(x/g,y/g);
    }
    num operator *(const int &other) const
    {
        int x=a*other,y=b,g=gcd(x,y);
        return num(x/g,y/g);
    }
}T;
struct element
{
    int t,c,x,y;
}q[200001];
int n,m,dep[200001],fa[200001],s[200001],son[200001],top[200001],qk[3000001],qb[3000001],cnt;
double ans;
num ql[3000001],qr[3000001];
vector<int> v[200001],a[200001];
struct cmp
{
    bool operator ()(int x,int y) const
    {
        num a=T*qk[x]+qb[x],b=T*qk[y]+qb[y];
        return a==b? x<y:a<b;
    }
};
set<int,cmp> st;
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
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k]=f;
    s[k]=1;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs1(i,k,deep+1);
        s[k]+=s[i];
        if(s[i]>s[son[k]])
            son[k]=i;
    }
}
inline void dfs2(int k,int t)
{
    top[k]=t;
    if(!son[k])
        return;
    dfs2(son[k],t);
    for(int i:v[k])
    {
        if(i==fa[k]||i==son[k])
            continue;
        dfs2(i,i);
    }
}
inline int LCA(int x,int y)
{
    while(top[x]^top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    return x;
}
inline int dis(int x,int y)
{
    return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);
}
inline void update(int t,int c,int x,int y)
{
    int d=dis(x,y),dx=0,dy=d;
    t*=c;
    while(top[x]^top[y])
    {
        ++cnt;
        if(dep[top[x]]>dep[top[y]])
        {
            ql[cnt]=num(t+dx,c);
            dx+=dep[x]-dep[top[x]]+1;
            qr[cnt]=num(t+dx,c);
            qk[cnt]=-c;
            qb[cnt]=dx+t;
            a[top[x]].emplace_back(-cnt);
            a[top[x]].emplace_back(cnt);
            x=fa[top[x]];
        }
        else
        {
            qr[cnt]=num(t+dy,c);
            dy-=dep[y]-dep[top[y]]+1;
            ql[cnt]=num(t+dy,c);
            qk[cnt]=c;
            qb[cnt]=-dy-t;
            a[top[y]].emplace_back(-cnt);
            a[top[y]].emplace_back(cnt);
            y=fa[top[y]];
        }
    }
    ++cnt;
    ql[cnt]=num(t+dx,c);
    qr[cnt]=num(t+dy,c);
    if(dep[x]<dep[y])
    {
        qk[cnt]=c;
        qb[cnt]=dep[x]-dep[top[x]]+1-dx-t;
    }
    else
    {
        qk[cnt]=-c;
        qb[cnt]=dep[x]-dep[top[x]]+1+dx+t;
    }
    a[top[x]].emplace_back(-cnt);
    a[top[x]].emplace_back(cnt);
}
inline void query(int k)
{
    sort(a[k].begin(),a[k].end(),[&](int x,int y){num a=x<0? ql[-x]:qr[x],b=y<0? ql[-y]:qr[y];return a==b? x<y:a<b;});
    st.clear();
    int tot=0;
    num tmp;
    for(int i:a[k])
    {
        T=i<0? ql[-i]:qr[i];
        if(tot&&!(T<tmp))
            break;
        if(i<0)
        {
            i=-i;
            auto it=st.insert(i).first,pre=it,nxt=it;
            if(pre==st.begin())
                pre=st.end();
            else
                pre=prev(it);
            nxt=next(it);
            if(pre!=st.end())
            {
                num l=max(ql[i],ql[*pre]),r=min(qr[i],qr[*pre]);
                if(qk[i]==qk[*pre])
                {
                    if(qb[i]==qb[*pre])
                    {
                        if(!tot)
                        {
                            tot=1;
                            tmp=l;
                        }
                        else
                            tmp=min(tmp,l);
                    }
                }
                else
                {
                    num val(qb[i]-qb[*pre],qk[*pre]-qk[i]);
                    if(!(val<l)&&!(r<val))
                    {
                        if(!tot)
                        {
                            tot=1;
                            tmp=val;
                        }
                        else
                            tmp=min(tmp,val);
                    }
                }
            }
            if(nxt!=st.end())
            {
                num l=max(ql[i],ql[*nxt]),r=min(qr[i],qr[*nxt]);
                if(qk[i]==qk[*nxt])
                {
                    if(qb[i]==qb[*nxt])
                    {
                        if(!tot)
                        {
                            tot=1;
                            tmp=l;
                        }
                        else
                            tmp=min(tmp,l);
                    }
                }
                else
                {
                    num val(qb[i]-qb[*nxt],qk[*nxt]-qk[i]);
                    if(!(val<l)&&!(r<val))
                    {
                        if(!tot)
                        {
                            tot=1;
                            tmp=val;
                        }
                        else
                            tmp=min(tmp,val);
                    }
                }
            }
        }
        else
        {
            auto it=st.erase(st.find(i));
            if(it==st.end()||it==st.begin())
                continue;
            auto pre=prev(it);
            num l=max(ql[*it],ql[*pre]),r=min(qr[*it],qr[*pre]);
            if(qk[*it]==qk[*pre])
            {
                if(qb[*it]==qb[*pre])
                {
                    if(!tot)
                    {
                        tot=1;
                        tmp=l;
                    }
                    else
                        tmp=min(tmp,l);
                }
            }
            else
            {
                num val(qb[*it]-qb[*pre],qk[*pre]-qk[*it]);
                if(!(val<l)&&!(r<val))
                {
                    if(!tot)
                    {
                        tot=1;
                        tmp=val;
                    }
                    else
                        tmp=min(tmp,val);
                }
            }
        }
    }
    if(tot)
        ans=min(ans,1.*tmp.a/(tmp.b+1e-10));
}
signed main()
{
    n=read(),m=read();
    ans=1e18;
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=1;i<=m;++i)
    {
        q[i].t=read(),q[i].c=read(),q[i].x=read(),q[i].y=read();
        update(q[i].t,q[i].c,q[i].x,q[i].y);
    }
    for(int i=1;i<=n;++i)
        if(i==top[i])
            query(i);
    if(ans<1e18)
        printf("%.10lf\n",ans);
    else
        cout<<"-1\n";
    return 0;
}