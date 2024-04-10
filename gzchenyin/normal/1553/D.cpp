#include<cstdio>
#include<cstring>
using namespace std;
int n,m,T;
char s[100005],t[100005];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        scanf("%s",t+1);
        n=strlen(s+1);
        m=strlen(t+1);
        if(n<m) 
        {
            printf("NO\n");
            continue;
        }
        if((n%2)!=(m%2))
        {
            for(int i=1;i<=n;i++)
            {
                s[i]=s[i+1];
            }
            n--;
        }
        int Now=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]==t[Now])
            {
                Now++;
            }
            else
            {
                i++;
            }
        }
        if(Now==m+1) printf("YES\n");
        else printf("NO\n");
    }
}