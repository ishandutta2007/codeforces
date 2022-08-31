#include<bits/stdc++.h>
#define maxn 5005

using namespace std;
char s[maxn],t[maxn];
int n,k,r,c,m;
bool f[maxn],g[maxn];

int main()
{
    scanf("%s",s); n=strlen(s); k=0;r=1;
    while (r*2<=n) r*=2,k++;
    m=n-r+1; memset(f,true,sizeof(f));
    for (int i=0;i<m;i++)
    {
        t[i]='z';
        for (int j=0;j<r;j++) if (f[j]&&s[j+i]<t[i]) t[i]=s[j+i];
        memset(g,false,sizeof(g));
        for (int j=0;j<r;j++) if (f[j]&&s[j+i]==t[i]){
            if (g[j]) continue; c=r-1-j;
            for (int j=c;;j=(j-1)&c)
            {
                g[r-1-j]=true;
                if (!j) break;
            }
        }
        for (int j=0;j<r;j++) f[j]=g[j];
    }
    for (int i=0;i<m;i++) printf("%c",t[i]); printf("\n");
    return 0;
}