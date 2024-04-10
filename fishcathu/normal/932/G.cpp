#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E6+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N],b[N];
int nex[N][26],fa[N],len[N],dif[N],pre[N],cnt,las;
int f[N],ans[N];
int find(int x,int i){while(a[i-len[x]-1]^a[i])x=fa[x];return x;}
void ins(int i)
{
    int x=a[i]-97,p=find(las,i);
    if(!nex[p][x])
    {
        fa[++cnt]=nex[find(fa[p],i)][x];
        nex[p][x]=cnt;
        len[cnt]=len[p]+2;
        dif[cnt]=len[cnt]-len[fa[cnt]];
        pre[cnt]=dif[cnt]^dif[fa[cnt]]?fa[cnt]:pre[fa[cnt]];
    }
    las=nex[p][x];
}
int main()
{
    const int p=1E9+7;
    len[fa[0]=++cnt]=-1;
    scanf("%s",b+1);
    int n=strlen(b+1);
    for(int i=0,j=1,k=n;j<k;a[++i]=b[j++],a[++i]=b[k--]);
    ans[0]=1;
    for(int i=1;i<=n;++i)
    {
        ins(i);
        for(int j=las;j;j=pre[j])
        {
            f[j]=ans[i-len[pre[j]]-dif[j]];
            if(fa[j]^pre[j])f[j]=(f[j]+f[fa[j]])%p;
            if(!(i&1))ans[i]=(ans[i]+f[j])%p;
        }
    }
    write(ans[n],'\n');
}