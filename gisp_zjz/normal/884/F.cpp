#include<bits/stdc++.h>
#define maxn 1005

using namespace std;

char s[maxn];
int a[maxn],b[maxn],t,n,c[maxn],d[maxn],r,e,ans;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=0;i<n;i++) a[i]=s[i]-'a'; ans=0;
    for (int i=0;i<n;i++) {scanf("%d",&b[i]);ans+=b[i];}
    t=0;memset(c,0,sizeof(c));t=0;
    for (int i=0;i<n/2;i++)
    {
        if (a[i]==a[n-1-i]) ans-=min(b[i],b[n-1-i]),c[a[i]]++,t++;
    }
    r=-1;e=0;
    for (int i=0;i<26;i++) if (c[i]*2>t) r=i;
    if (r!=-1)
    {
        for (int i=0;i<n/2;i++) if (a[i]!=a[n-1-i]&&a[i]!=r&&a[n-1-i]!=r) d[e++]=min(b[i],b[n-1-i]);
        sort(d,d+e);
        for (int i=0;i<c[r]*2-t;i++) ans-=d[i];
    }
    printf("%d\n",ans);
    return 0;
}