#include<stdio.h>
#include<string.h>
#include<math.h> 
int sum=0,sum2=0,q2=0;
double ans=0;
void dfs(int s)
{
    if(s==0)
    {
    if(sum2==sum)
    ans++;
    }
    else
    {
    sum2++;
    dfs(s-1);
    
    sum2-=2;
    dfs(s-1);
    sum2++;
    }
}
main()
{
    char a1[100],a2[100];
    scanf("%s %s",a1,a2);
    for(int i=0;i<strlen(a1);i++)
    {
        if(a1[i]=='+')
        sum++;
        else
        sum--;
    }
    for(int i=0;i<strlen(a2);i++)
    {
        if(a2[i]=='+')
        sum2++;
        else if(a2[i]=='-')
        sum2--;
        else
        q2++;
    }
    dfs(q2);
    printf("%.12lf",ans/pow(2,q2));
    return 0;
}