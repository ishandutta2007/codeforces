#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct element
{
    int opt,x,y,w;
};
int n,m,q,cnt,bin[200001],val[200001],s[200001],p[400001<<2][41],t[400001];
bool vis[400001];
element e[400001];
vector<element> v[400001<<2];
map<pair<int,int>,int> mp;
vector<pair<int,int> > tmp[400001<<2];
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline void insert(int x,int tag)
{
    for(int i=30;~i;--i)
    {
        if(!(x&(1<<i)))
            continue;
        if(!p[tag][i])
        {
            p[tag][i]=x;
            return;
        }
        x^=p[tag][i];
    }
}
inline int query(int x,int tag)
{
    int res=x;
    for(int i=30;~i;--i)
        if(res&(1<<i))
            res^=p[tag][i];
    return res;
}
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return anc(bin[k]);
}
inline int query(int k)
{
    if(!bin[k])
        return 0;
    return val[k]^query(bin[k]);
}
inline pair<int,int> link(int x,int y,int w,int tag)
{
    int tmpx=x,tmpy=y;
    x=anc(x);
    y=anc(y);
    if(x^y)
    {
        if(s[x]<s[y])
        {
            x^=y^=x^=y;
            tmpx^=tmpy^=tmpx^=tmpy;
        }
        bin[y]=x;
        s[x]+=s[y];
        val[y]=0;
        val[y]=query(tmpx)^query(tmpy)^w;
        return {x,y};
    }
    insert(query(tmpx)^query(tmpy)^w,tag);
    return {0,0};
}
inline void cut(int x,int y)
{
    if(!x&&!y)
        return;
    bin[y]=0;
    s[x]-=s[y];
    val[y]=0;
}
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void update(int nl,int nr,int l,int r,int k,element p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        v[k].push_back(p);
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
}
inline void query(int l,int r,int k)
{
    for(element i:v[k])
        if(!i.opt)
            tmp[k].push_back(link(i.x,i.y,i.w,k));
    for(element i:v[k])
        if(i.opt)
        {
            print(query(query(i.x)^query(i.y),k));
            putchar('\n');
        }
    if(l==r)
    {
        reverse(tmp[k].begin(),tmp[k].end());
        for(pair<int,int> i:tmp[k])
            cut(i.first,i.second);
        return;
    }
    int mid=(l+r)>>1;
    for(int i=0;i<=30;++i)
        p[ls(k)][i]=p[rs(k)][i]=p[k][i];
    query(l,mid,ls(k));
    query(mid+1,r,rs(k));
    reverse(tmp[k].begin(),tmp[k].end());
    for(pair<int,int> i:tmp[k])
        cut(i.first,i.second);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        s[i]=1;
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        if(x>y)
            x^=y^=x^=y;
        mp[{x,y}]=i;
        e[++cnt]={0,x,y,w};
        t[cnt]=i;
    }
    q=read();
    for(int i=1;i<=q;++i)
    {
        int opt=read();
        if(opt==1)
        {
            int x=read(),y=read(),w=read();
            if(x>y)
                x^=y^=x^=y;
            mp[{x,y}]=++cnt;
            e[cnt]={0,x,y,w};
            t[cnt]=i+m;
        }
        if(opt==2)
        {
            int x=read(),y=read();
            if(x>y)
                x^=y^=x^=y;
            int pos=mp[{x,y}];
            vis[pos]=1;
            update(t[pos],i+m-1,1,m+q,1,e[pos]);
            //cout<<t[mp[{x,y}]]<<" "<<i+m-1<<" "<<mp[{x,y}]<<endl;
            mp.erase({x,y});
        }
        if(opt==3)
        {
            int x=read(),y=read();
            if(x>y)
                x^=y^=x^=y;
            update(i+m,i+m,1,m+q,1,{1,x,y,0});
            //cout<<i+m<<" "<<x<<" "<<y<<endl;
        }
    }
    for(int i=1;i<=cnt;++i)
        if(!vis[i])
        {
            update(t[i],m+q,1,m+q,1,e[i]);
            //cout<<t[i]<<" "<<m+q<<" "<<i<<endl;
        }
    query(1,m+q,1);
    return 0;
}