#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=4E6+10;
const int inf=4E6+9;
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
int to[N],ans[N];
int q[N],pos[N],cnt;
void dfs(int x)
{
    q[++cnt]=x;
    pos[x]=cnt;
    if(!pos[to[x]])dfs(to[x]);
}
void solve()
{
    int n=read(),m=read(),s=n*m;
    for(int i=0;i<s;++i)to[i]=inf,pos[i]=ans[i]=0;
    for(int i=0,k=0;i<n;++i)
    {
        for(int j=0;j<m;++j,++k)
        {
            char c;
            do c=getchar();while(c<65);
            if(c=='L'){if(j)to[k]=k-1;}
            else if(c=='R'){if(j^m-1)to[k]=k+1;}
            else if(c=='U'){if(i)to[k]=k-m;}
            else if(i^n-1)to[k]=k+m;
        }
    }
    cnt=0;
    for(int i=0;i<s;++i)
    {
        if(pos[i])continue;
        dfs(i);
        int t=to[q[cnt]];
        if(t^inf&&!ans[t])
        {
            int w=cnt-pos[t]+1;
            while(1)
            {
                int x=q[cnt--];
                ans[x]=w;
                if(x==t)break;
            }
        }
        while(cnt)
        {
            int x=q[cnt--];
            ans[x]=ans[to[x]]+1;
        }
    }
    int res=max_element(ans,ans+s)-ans;
    printf("%d %d %d\n",res/m+1,res%m+1,ans[res]);
}
int main()
{
    pos[inf]=-1;
    for(int x=read();x--;)
    {
        solve();
    }
}