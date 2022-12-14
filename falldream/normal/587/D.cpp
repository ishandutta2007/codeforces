#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#define pa pair<int,int>
#define MN 50000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define Rev(x) ((x&1)?x+1:x-1)
namespace SAT2
{
    #define MX 400000
    vector<int> v[MX+5],V[MX+5];
    int n,b[MX+5],dn,q[MX+5],mark[MX+5],num,yes[MX+5];
    void init(int sz)
    {
        for(int i=1;i<=sz;++i) v[i].clear(),V[i].clear(),mark[i]=b[i]=yes[i]=0;
        dn=num=0;n=sz;
    }
    void ins(int f,int t)
    {
        v[f].push_back(t);
        v[Rev(t)].push_back(Rev(f));
        V[t].push_back(f);
        V[Rev(f)].push_back(Rev(t));
    }
    void dfs(int x)
    {
        b[x]=1;
        for(int i=0;i<v[x].size();++i)
            if(!b[v[x][i]]) dfs(v[x][i]);
        q[++dn]=x;
    }
    void rdfs(int x)
    {
        mark[x]=num;
        for(int i=0;i<V[x].size();++i)
            if(!mark[V[x][i]]) rdfs(V[x][i]);
    }
    bool Solve()
    {
        for(int i=1;i<=n;++i)
            if(!b[i]) dfs(i);
        for(int i=n;i;--i)
            if(!mark[q[i]]) ++num,rdfs(q[i]);
        for(int i=1;i<=n;++i) if(mark[i]==mark[Rev(i)]) return false;
        for(int i=1;i<=n;++i) yes[mark[i]>mark[Rev(i)]?i:Rev(i)]=1;
        return true;
    }
}
int n,m;
struct edge{int to,c,t,id;};vector<edge> v[MN+5];
bool cmp(const edge&a,const edge&b){return a.c<b.c;}
inline void ins(int f,int t,int c,int T,int id){v[f].push_back((edge){t,c,T,id});}

bool Solve(int T)
{
   // cout<<"beginSolve"<<T<<endl;
    SAT2::init(m<<3);
    for(int i=1;i<=n;++i)
    {
        int C=0,pre=0;
        for(int j=0;j<v[i].size();++j)
        {
         //   cout<<i<<" "<<v[i][j].to<<" "<<v[i][j].c<<" "<<v[i][j].t<<" "<<v[i][j].id<<endl;
            SAT2::ins(v[i][j].id,(v[i][j].id+2*m)%(4*m));
            SAT2::ins(Rev(v[i][j].id),Rev((v[i][j].id+2*m)%(4*m)));
            SAT2::ins(v[i][j].id,v[i][j].id+4*m);
            if(pre)
            {
                SAT2::ins(pre+4*m,Rev(v[i][j].id));
                SAT2::ins(pre+4*m,v[i][j].id+4*m);
            }
            if(C==v[i][j].c)
            {
               // cout<<"!!!"<<endl;
                SAT2::ins(v[i][j].id,Rev(pre));
                SAT2::ins(Rev(v[i][j].id),pre);
            }
            if(v[i][j].t>T) SAT2::ins(v[i][j].id,Rev(v[i][j].id));
            C=v[i][j].c,pre=v[i][j].id;
        }
    }
   // cout<<endl;
    return SAT2::Solve();
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),c=read(),t=read();
        ins(x,y,c,t,2*i-1);ins(y,x,c,t,2*m+2*i-1);
    }
    for(int i=1;i<=n;++i)
    {
        sort(v[i].begin(),v[i].end(),cmp);
        int C=0,num=0;
        for(int j=0;j<v[i].size();C=v[i][j++].c)
            num+=v[i][j].c==C;
        if(num>1) return 0*puts("No");
    }
    int l=0,r=1e9,mid,res=-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(Solve(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    if(res==-1) return 0*puts("No");
    printf("Yes\n%d ",res);Solve(res);
    vector<int> ans;
    for(int i=1;i<=m;++i)
        if(SAT2::yes[i*2-1]) ans.push_back(i);
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();++i) printf("%d ",ans[i]);
    return 0;
}