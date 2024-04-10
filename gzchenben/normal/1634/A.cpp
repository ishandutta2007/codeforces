#include<cstdio>
using namespace std;
int n,k,t;
char s[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf(" %c",&s[i]);
        }
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=s[n-i+1]) flag=true;
        }
        if(k!=0 && flag) printf("2\n");
        else printf("1\n");
    }
}