#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int n,l,r,c[N];
void clear(){for(int i=1;i<=n;i++) c[i]=0;}
void solve()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(i<=l) c[x]--;
        else c[x]++;
    }
    int t=0,s0=0,s1=0,t0=0,t1=0;
    for(int i=1;i<=n;i++)
    if(c[i]>0) s0+=c[i]/2,t0+=c[i]%2;
    else s1+=-c[i]/2,t1+=(-c[i])%2;
    int x=min(t0,t1);
    t0-=x;t1-=x;t+=x;
    x=min(t0,s1*2);
    t0-=x;s1-=x/2;t+=x;
    x=min(t1,s0*2);
    t1-=x;s0-=x/2;t+=x;
    x=min(s0*2,s1*2);
    t0-=x/2;s0-=x/2;t+=x;
    if(t0) t+=t0;
    if(t1) t+=t1;
    if(s0) t+=s0;
    if(s1) t+=s1;
    printf("%d\n",t);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0){solve();clear();}
    return 0;
}