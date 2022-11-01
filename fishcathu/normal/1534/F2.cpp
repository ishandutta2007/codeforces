#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=4E5+10;
const int inf=1<<30;
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
int n,m;
bitset<N>a;
int l[N],r[N],f[N];
void dfs(int i,int j,int w,int *l)
{
    int t=i*m+j;
    if(~l[t])return;
    l[t]=w;
    if(i+1<n)dfs(i+1,j,w,l);
    if(i&&a[t-m])dfs(i-1,j,w,l);
    if(j&&a[t-1])dfs(i,j-1,w,l);
    if(j+1<m&&a[t+1])dfs(i,j+1,w,l);
}
int main()
{

    n=read(),m=read();
    for(int i=0,j=n*m;i<j;++i)
    {
        char c;
        do c=getchar();while(c<35);
        a[i]=c&1;
        l[i]=r[i]=-1;
    }
    for(int j=0;j<m;++j)
    {
        int i=0;
        while(i<n&&!a[i*m+j])++i;
        if(i<n)dfs(i,j,j,l);
    }
    for(int j=m;j--;)
    {
        f[j]=m;
        int i=0;
        while(i<n&&!a[i*m+j])++i;
        if(i<n)dfs(i,j,j,r);
    }
    for(int j=0;j<m;++j)
    {
        int s=read();
        if(!s)continue;
        int i=n;
        while(s)
        {
            if(a[--i*m+j])
            {
                --s;
            }
        }
        i=i*m+j;
        f[l[i]]=min(f[l[i]],r[i]);
    }
    int ans=0;
    for(int i=0,j=m;i<m;++i)
    {
        j=min(j,f[i]);
        if(i==j)
        {
            ++ans;
            j=m;
        }
    }
    write(ans,'\n');
}