#include<bits/stdc++.h>
using namespace std;

const int N=311;

int T;

int n,m,vis[N],stp[N];

char s[N],t[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s+1,t+1);
        n=strlen(s+1),m=strlen(t+1);
        int p=m;
        for(int i=1;i<=n;i++)
            vis[i]=0;
        for(int i=n;i>=1;i--)
        {
            if(s[i]==t[p])
                p--,vis[i]=1;
        }
        if(p>0)
            puts("NO");
        else
        {
            fill(stp,stp+26,0);
            bool ok=1;
            for(int i=1;i<=n;i++)
            {
                if(vis[i])
                    stp[s[i]-'A']=1;
                else
                {
                    if(stp[s[i]-'A'])
                        ok=0;
                }
            }
            puts(ok?"YES":"NO");
        }
    }
}