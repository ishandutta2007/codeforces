#include<cstdio>
#include<cstring>
using namespace std;
int n,t,ans;
char s[100005];
bool del[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=2;i<=n;i++)
        {
            if((s[i]==s[i-1] && !del[i-1]) || (s[i]==s[i-2] && !del[i-2]))
            {
                ans++;
                del[i]=true;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
        {
            del[i]=false;
        }
    }
}