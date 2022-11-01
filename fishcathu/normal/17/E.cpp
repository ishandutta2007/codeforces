#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E6+10;
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
const int p=51123987;
char a[N];
int fail[N],len[N],num[N],q[N],cur,cnt=1;
vector<pii>to[N];
int findfail(int x,int i){while(a[i-len[x]-1]^a[i])x=fail[x];return x;}
int nex(int x,int i){for(auto [u,v]:to[x])if(u==i)return v;return 0;}
int ins(int i)
{
    int x=a[i]-97,p=findfail(cur,i);
    if(!nex(p,x))
    {
        fail[++cnt]=nex(findfail(fail[p],i),x);
        to[p].pb({x,cnt});
        len[cnt]=len[p]+2;
        num[cnt]=num[fail[cnt]]+1;
    }
    cur=nex(p,x);
    return num[cur];
}
int main()
{
    fail[0]=1;
    len[1]=-1;
    int n=read();
    scanf("%s",a+1);
    for(int i=1;i<=n;++i)q[i]=(q[i-1]+ins(i))%p;
    int ans=q[n]*(q[n]-1LL)/2%p;
    cur=0;
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;++i)ans=((ans-ins(i)*1LL*q[n-i])%p+p)%p;
    write(ans,'\n');
}