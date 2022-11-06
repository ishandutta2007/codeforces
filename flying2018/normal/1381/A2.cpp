#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 200010
using namespace std;
char s[N];
bool s1[N],s2[N],rev[N];
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
        int l=1,r=n;
        bool swp=0;
        for(int i=n;i>=1;i--)
        {
            if(swp)
            {
                if(s1[r]!=s2[i]) rev[i]^=1;
                r--;
            }
            else
            {
                if(s1[l]==s2[i]) rev[i]^=1;
                l++;
            }
            swp=!swp;
        }
        for(int i=n;i>=1;i--)
        {
            if(rev[i]) ans[++tot]=1;
            ans[++tot]=i;
        }
        printf("%d ",tot);
        for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
        puts("");
        for(int i=1;i<=n;i++) rev[i]=0;
    }
    return 0;
}