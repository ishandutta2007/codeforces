#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int val[N];
char op[2];
int ton[N],ans[N],tt;
int rt;
bool fl[N];
int tg[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%s",op);
        if(op[0]=='+') ton[++tt]=++rt;
        else
        {
            int x;
            scanf("%d",&x);
            if(!tt || fl[x]){puts("NO");return 0;}
            fl[x]=1;
            if(tg[ton[tt]]>x){puts("NO");return 0;}
            tg[ton[tt]]=x;
            --tt;
            tg[ton[tt]]=max(tg[ton[tt]],tg[ton[tt+1]]);
        }
    }
    for(int i=1;i<=n;i++) val[tg[i]]++;
    for(int i=n;i;i--)
    {
        val[i]+=val[i+1];
        if(val[i]>n-i+1){puts("NO");return 0;}
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",tg[i]);
    return 0;
}