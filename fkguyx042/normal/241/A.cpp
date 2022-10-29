#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;
struct Node
{int c,d;}node[1010];
int m,k;
ll t=0;

int deal()
{
    int i ;
    int s=0;
    int dis=0;
    int maxc=0;
    for(i=1;i<=m;i++)
    {
        if(node[i].c>maxc) maxc=node[i].c;
        dis+=node[i].d;
        s+=node[i].c;
        while(s<dis)
        {s+=maxc;t++;}
    }
    s=dis+t*k;
    return s;
}
int main()
{    scanf("%d%d",&m,&k);
        for(int i=1;i<=m;i++)
            scanf("%d",&node[i].d);
        for(int i=1;i<=m;i++)
            scanf("%d",&node[i].c);
        printf("%d\n",deal());
    return 0;
}