#include<stdio.h>
#include<string.h>
main()
{
    char s[100000];
    int right=0 ,left=0,ans=0,right1=0,left1=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
            left++;
        if(s[i]==')')
            right++;
        if(s[i]=='#')
            ans++;
        if(right+ans>left)
        {
            printf("-1");
            return 0;
        }
    }
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='(')
            left1++;
        if(s[i]==')')
            right1++;
        if(s[i]=='#')
            break;
        if(left1>right1)
        {
            printf("-1");
            return 0;
        }
    }
    for(int i=0;i<ans-1;i++)
    printf("1\n");
    printf("%d\n",left-right-ans+1);
    
    return 0;
}