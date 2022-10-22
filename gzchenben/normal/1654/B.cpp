#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
char s[200005];
int lst[205];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i='a';i<='z';i++) lst[i]=0;
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++)
        {
            lst[s[i]]=i;
        }
        int ans=n+1;
        for(int i='a';i<='z';i++) if(lst[i]) ans=min(ans,lst[i]);
        for(int i=ans;i<=n;i++) printf("%c",s[i]);
        printf("\n");
    }
}