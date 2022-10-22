#include<cstdio>
using namespace std;
int n,t;
char s[105];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf(" %c",&s[i]);
            if(s[i]=='U') printf("D");
            if(s[i]=='D') printf("U");
            if(s[i]=='L') printf("L");
            if(s[i]=='R') printf("R");
        }
        printf("\n");
    }
}