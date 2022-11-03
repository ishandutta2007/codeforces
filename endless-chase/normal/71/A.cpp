#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[105];
    while(n--)
    {
        scanf("%s",&s);
        int len=strlen(s);
        if(len<=10)
            printf("%s\n",s);
        else
            printf("%c%d%c\n",s[0],(len-2),s[len-1]);
    }
}