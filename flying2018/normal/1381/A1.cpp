#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 100010
using namespace std;
char s[N];
bool s1[N],s2[N];
int ans[N],tot;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        tot=0;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) s1[i]=s[i]-'0';
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) s2[i]=s[i]-'0';
        for(int i=n;i>=1;i--)
        if(s1[i]!=s2[i])
        {
            if(s1[1]==s2[i])
            {
                ans[++tot]=1;
                s1[1]=!s1[1];
            }
            ans[++tot]=i;
            reverse(s1+1,s1+i+1);
            for(int j=1;j<=i;j++) s1[j]=!s1[j];
        }
        printf("%d ",tot);
        for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}