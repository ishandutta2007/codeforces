#include<iostream>
#include<cstdio>
#include<cstring>
#define N 600010
#define ll long long
using namespace std;
char s[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d%s",&n,s+1);
        for(int i=1;i<=n;i++) s[i+n]=s[i];
        s[2*n+1]=s[2*n+2]='\0';
        ll ans=0;
        bool onc=true;
        for(int i=2;i<=n;i++) if(s[i]!=s[i-1]) onc=false;
        if(onc)
        {
            printf("%d\n",(n+2)/3);
            continue;
        }
        int p=n;
        for(;s[p]=='R';p--);
        for(;s[p]=='L';p++);
        if(p>n) p-=n;
        for(int i=p;i<p+n;)
        {
            int j=i;
            while(s[j]=='R' && j<p+n) j++;
            int r=j-i,j1=j;
            while(s[j]=='L' && j<p+n) j++;
            int r1=j-j1;
            ans+=r/3+r1/3;
            i=j;
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n*2+5;i++) s[i]='\0';
    }
    return 0;
}