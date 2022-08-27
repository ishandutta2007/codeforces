#include<bits/stdc++.h>

using namespace std;

int n,m,x,y,c;

int ans[1000000],cnt;

int main()
{
    scanf("%d%d%d",&n,&x,&c);
    scanf("%d%d",&m,&y);
    cnt=0;
    while (m>0)
    {
        if (x>=m) m-=x,ans[cnt++]=1;
        else if (y>=n) n+=c-y,ans[cnt++]=0;
        else n-=y,m-=x,ans[cnt++]=1;
    }
    printf("%d\n",cnt);
    for (int i=0;i<cnt;i++) if (ans[i]) printf("STRIKE\n"); else printf("HEAL\n");
    return 0;
}