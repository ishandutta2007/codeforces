#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int n,x;
void clear(){}
int w[N];
void solve()
{
    scanf("%d%d",&n,&x);
    int s=0;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),s+=w[i];
    if(s==x){puts("NO");return;}
    puts("YES");
    s=0;
    for(int i=1;i<=n;i++)
    {
        if(s+w[i]==x) swap(w[i],w[i+1]);
        s+=w[i];
        printf("%d ",w[i]);
    }
    puts("");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0){solve();clear();}
    return 0;
}