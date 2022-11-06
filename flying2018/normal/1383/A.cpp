#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
char s1[N],s2[N];
void work()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",s1+1,s2+1);
    for(int j=1;j<=n;j++)
        if(s1[j]>s2[j]){puts("-1");return;}
    int ans=0;
    for(int i=1;i<=20;i++)
    {
        int ch=21;
        for(int j=1;j<=n;j++)
        if(s1[j]-'a'+1==i && s2[j]-'a'+1!=i) ch=min(ch,s2[j]-'a'+1);
        if(ch>20) continue;
        for(int j=1;j<=n;j++)
        if(s1[j]-'a'+1==i && s2[j]-'a'+1!=i) s1[j]='a'+ch-1;
        ++ans;
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0) work();
    return 0;
}