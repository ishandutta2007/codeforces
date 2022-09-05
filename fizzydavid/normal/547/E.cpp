// speed++! 
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
#define findpos(v,x) lower_bound(v.begin(),v.end(),x)-v.begin()

int n,q,pos[400111],sa[400111],lcp[400111],L[400111],R[400111],sn;
char s[400111];
int ans[500111],sz[400111];
vector<pair<int,int> >query[400111];
int tmp[400111],rk[400111];
int sak;
bool cmp2(int x,int y)
{
    if(rk[x]!=rk[y])return rk[x]<rk[y];
    else
    {
        int t1=x+sak<=sn?rk[x+sak]:-1;
        int t2=y+sak<=sn?rk[y+sak]:-1;
        return t1<t2;
    }
}
vector<int>buk[400111];
void initsa()
{
    for(int i=0;i<=sn;i++)
    {
        sa[i]=i;
        rk[i]=i<sn?s[i]:-1;
    }
    for(int i=1;i<=sn;i*=2)
    {
        sak=i;
        for(int j=0;j<=400011;j++)buk[j].clear();
        for(int j=0;j<=sn;j++)buk[(sa[j]+sak<=sn?rk[sa[j]+sak]:-1)+1].PB(sa[j]);
        int t=0;
        for(int j=0;j<=400011;j++)
            for(int k=0;k<buk[j].size();k++)
                sa[t++]=buk[j][k];
        for(int j=0;j<=400011;j++)buk[j].clear();
        for(int j=0;j<=sn;j++)buk[rk[sa[j]]+1].PB(sa[j]);
        t=0;
        for(int j=0;j<=400011;j++)
            for(int k=0;k<buk[j].size();k++)
                sa[t++]=buk[j][k];
        tmp[sa[0]]=0;
        for(int j=1;j<=sn;j++)
        {
            tmp[sa[j]]=cmp2(sa[j-1],sa[j])+tmp[sa[j-1]];
        }
        for(int j=0;j<=sn;j++)
        {
            rk[j]=tmp[j];
        }
    }
    for(int i=0;i<=sn;i++)rk[sa[i]]=i;
    lcp[0]=0;
    int len=0;
    for(int i=0;i<sn;i++)
    {
        if(len>0)len--;
        int k=sa[rk[i]-1];
        while(i+len<sn&&k+len<sn&&s[i+len]==s[k+len])len++;
        lcp[rk[i]-1]=len;
    }
}

struct STtable
{
    int a[400111][23];
    int pow2[400111];
    void init(int size)
    {
        int base=0;
        for(int i=1;i<=400100;i++)
        {
            if((1<<(base+1))<=i)base++;
            pow2[i]=base;
        }
        memset(a,0,sizeof(a));
        for(int i=0;i<size;i++)a[i][0]=lcp[i];
        for(int k=1;k<23;k++)
        {
            for(int i=0;i<size-(1<<k)+1;i++)
            {
                a[i][k]=min(a[i][k-1],a[i+(1<<(k-1))][k-1]);
            }
        }
    }
    int query(int l,int r)
    {
        return min(a[l][pow2[r-l+1]],a[r-(1<<pow2[r-l+1])+1][pow2[r-l+1]]);
    }
}stt;

struct BIT
{
    int a[400111];
    BIT()
    {
        memset(a,0,sizeof(a));
    }
    void add(int id)
    {
        while(id<=400011)
        {
            a[id]++;
            id+=id&(-id);
        }
    }
    int query(int id)
    {
        int ans=0;
        while(id>0)
        {
            ans+=a[id];
            id-=id&(-id);
        }
        return ans;
    }
}bit;

int main()
{
    getii(n,q);
    for(int i=1;i<=n;i++)
    {
        char c;
        while((c=getchar())!='\n')s[sn++]=c,sz[i]++;
        pos[i]=sn;s[sn++]=1;
    }
    pos[0]=-1;
    initsa();
    stt.init(sn);
    for(int i=1;i<=n;i++)
    {
        int cur=rk[pos[i-1]+1];
        int p=cur;
        for(int j=21;j>=0;j--)
        {
            if(p-(1<<j)>=0&&stt.query(p-(1<<j),cur-1)>=sz[i])
            {
                p-=1<<j;
            }
        }
        L[i]=p;
        p=cur;
        for(int j=21;j>=0;j--)
        {
            if(p+(1<<j)<=sn&&stt.query(cur,p+(1<<j)-1)>=sz[i])
            {
                p+=1<<j;
            }
        }
        R[i]=p;
    }
    for(int i=1;i<=q;i++)
    {
        int l,r,k;
        getiii(l,r,k);
        query[R[k]].PB(MP(pos[r]-1,i));
        if(pos[l-1]>0)query[R[k]].PB(MP(-(pos[l-1]),i));
        if(L[k]>0)
        {
            query[L[k]-1].PB(MP(-(pos[r]-1),i));
            if(pos[l-1]>0)query[L[k]-1].PB(MP(pos[l-1],i));
        }
    }
    for(int i=0;i<=sn;i++)
    {
        bit.add(sa[i]+1);
        for(int j=0;j<query[i].size();j++)
        {
            int tmp,x=query[i][j].FF;
            if(x<0)x=-x,tmp=-1;else tmp=1;
            ans[query[i][j].SS]+=tmp*bit.query(x+1);
        }
    }
    for(int i=1;i<=q;i++)
    {
        putsi(ans[i]);
    }
    return 0;
}