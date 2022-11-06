#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#define N 100010
using namespace std;
bitset<N>b[27],r;
char s[N],t[N];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1),m;
    for(int i=1;i<=n;i++)
    b[s[i]-'a'].set(i,1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int opt,x,y;
        scanf("%d%d",&opt,&x);
        if(opt==2)
        {
            scanf("%d%s",&y,t);
            int k=strlen(t),res=0;
            r.set();
            for(int j=0;j<k;j++) r&=b[t[j]-'a']>>j;
            int lf=(r>>x).count(),rf=(r>>(y-k+2)).count();
            if(lf<rf) lf=rf;
            printf("%d\n",lf-rf);
        }
        else
        {
            char c[2];
            scanf("%s",c);
            b[s[x]-'a'].set(x,0);
            s[x]=c[0];
            b[s[x]-'a'].set(x,1);
        }
    }
    return 0;
}