#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=3E5+10;
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
int a[N],b[N],pre[N],mn,n;
queue<int>q;
vector<int>ans;
void push(int x,int p){q.push(x),pre[x]=p,mn=x-1;}
void dfs(int x)
{
    if(x==n)return;
    dfs(pre[x]);
    ans.pb(x);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=i-read();
    for(int i=1;i<=n;++i)b[i]=i+read();
    push(n,inf);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int t=mn;t>=a[b[x]];--t)push(t,x);
    }
    if(!pre[0])puts("-1");
    else
    {
        dfs(0);
        write(ans.size(),'\n');
        for(int x:ans)write(x,' ');
    }
}