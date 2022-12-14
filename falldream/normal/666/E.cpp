#include<iostream>
#include<cstring>
#include<cstdio>
#define MD 19
#define MN 500001
#define pa pair<int,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
namespace SAM
{
#define MX 100001
    int cnt,c[MX+5][26],step[MX+5],fail[MX+5],v[MX+5],rk[MX+5];
    long long val[MX+5],sum[MX+5];
    void init(){cnt=1;}
    int insert(int last,int x)
    {
        //cout<<"insert"<<x+1<<endl;
        int p=last,np=++cnt;step[np]=step[p]+1;val[np]=1;
        for(;p&&!c[p][x];p=fail[p]) c[p][x]=np;
        if(!p) fail[np]=1;
        else
        {
            int q=c[p][x];
            if(step[q]==step[p]+1) fail[np]=q;
            else
            {
                int nq=++cnt;step[nq]=step[p]+1;
                memcpy(c[nq],c[q],sizeof(c[q]));
                fail[nq]=fail[q];fail[np]=fail[q]=nq;
                for(;c[p][x]==q;p=fail[p]) c[p][x]=nq;
            }
        }
        return np;
    }
#undef MX
}
char S[MN+5],s[MN+5];
struct Tree{int l,r;pa x;}T[MN*2*4+5];
struct edge{int to,next;}e[MN*2+5];
int n,cnt,rt[MN*2+5],len[MN+5],pos[MN+5],head[MN*2+5],en=0,fa[MD+1][MN+5];

inline void ins(int f,int t){e[++en]=(edge){t,head[f]};head[f]=en;}

inline pa Max(pa a,pa b){return a.first>=b.first?a:b;}
inline int newnode(int x){return x?x:++cnt;}
void Modify(int x,int lt,int rt,int v)
{
   // cout<<"Modify"<<x<<" "<<lt<<" "<<rt<<" "<<v<<endl;
    if(lt==rt){T[x].x=make_pair(T[x].x.first+1,lt);return;}
    int mid=lt+rt>>1;
    if(v<=mid) Modify(T[x].l=newnode(T[x].l),lt,mid,v);
    else Modify(T[x].r=newnode(T[x].r),mid+1,rt,v);
    T[x].x=Max(T[T[x].l].x,T[T[x].r].x);
}

int Merge(int x,int y,int lt,int rt)
{
 //   cout<<"Merge"<<x<<" "<<y<<" "<<lt<<" "<<rt<<endl;
    if(!x||!y) return x+y;
    int z=++cnt;
    if(lt!=rt)
    {
        int mid=lt+rt>>1;
        T[z].l=Merge(T[x].l,T[y].l,lt,mid);
        T[z].r=Merge(T[x].r,T[y].r,mid+1,rt);
        T[z].x=Max(T[T[z].l].x,T[T[z].r].x);
    }
    else T[z].x=make_pair(T[x].x.first+T[y].x.first,lt);
    return z;
}

void dfs(int x)
{
    for(int i=head[x];i;i=e[i].next)
        fa[0][e[i].to]=x,dfs(e[i].to),rt[x]=Merge(rt[x],rt[e[i].to],1,MN*2);
}

int get(int x,int l)
{
    for(int i=MD;~i;--i) if(SAM::step[fa[i][x]]>=l) x=fa[i][x];
    return x;
}

pa Query(int x,int l,int r,int lt,int rt)
{
  //  cout<<"Query"<<x<<" "<<l<<" "<<r<<" "<<lt<<" "<<rt<<endl;
    if(!x) return make_pair(0,0);
    if(l==lt&&r==rt) return T[x].x;
    int mid=lt+rt>>1;
    if(r<=mid) return Query(T[x].l,l,r,lt,mid);
    else if(l>mid) return Query(T[x].r,l,r,mid+1,rt);
    else return Max(Query(T[x].l,l,mid,lt,mid),Query(T[x].r,mid+1,r,mid+1,rt));
}

int main()
{
    SAM::init();scanf("%s",S+1);n=read();
    for(int i=1;i<=MN*2;++i) rt[i]=++cnt;
    for(int i=1;i<=n;++i)
    {
        scanf("%s",s+1);int x=1;
        for(int j=1;s[j];++j) x=SAM::insert(x,s[j]-'a'),Modify(rt[x],1,MN*2,i);
    }
    for(int i=1,x=1,l=0;S[i];++i)
    {
        using namespace SAM;
        int t=S[i]-'a';
        while(x&&!c[x][t]) l=step[x=fail[x]];
        if(x) pos[i]=(x=c[x][t]),len[i]=++l;
        else pos[i]=(x=1),len[i]=0;
    }
    for(int i=2;i<=SAM::cnt;++i) ins(SAM::fail[i],i);
    dfs(1);for(int j=1;j<=MD;++j)for(int i=1;i<=SAM::cnt;++i) fa[j][i]=fa[j-1][fa[j-1][i]];
    for(int Q=read();Q;--Q)
    {
        int l=read(),r=read(),L=read(),R=read();
        if(len[R]<R-L+1) {printf("%d 0\n",l);continue;}
        pa ans=Query(rt[get(pos[R],R-L+1)],l,r,1,MN*2);
        printf("%d %d\n",ans.first==0?l:ans.second,ans.first);
    }
    return 0;
}