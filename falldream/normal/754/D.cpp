#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n,m;
struct cp{
    int l,r,id;
}s[300005];
int ans=0,maxl,maxr;
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(cp x,cp y)
{return x.l<y.l;}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        s[i].l=read();s[i].r=read();s[i].id=i;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(q.size()<m) q.push(s[i].r);
        else if(s[i].r>q.top()){q.pop();q.push(s[i].r);}
        if(q.size()==m) if(q.top()-s[i].l+1>ans)
        {
            ans=q.top()-s[i].l+1;
            maxl=s[i].l;maxr=q.top();
        }
    }
    if(!ans){puts("0");for(int i=1;i<=m;i++)printf("%d ",i);return 0;}
    printf("%d\n",ans);
    for(int i=1;m&&i<=n;i++)
    {
        if(s[i].l<=maxl&&s[i].r>=maxr)
        {
            printf("%d ",s[i].id);m--;
        }
    }
    return 0;
}