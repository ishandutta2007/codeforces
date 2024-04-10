#include<stdio.h>
#include<string.h>
const char ans[100]={'q','w','e','r','t','y','u','i','o','p','[','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
main()
{
    char a[100],b;
    scanf("%c",&b);
    scanf("%s",a);
    if(b=='R')
    {
        for(int i=0;i<strlen(a);i++)
        for(int j=0;;j++)
        {
            if(a[i]==ans[j])
            {
            printf("%c",ans[j-1]);
            break;
            }
        }
    }
    if(b=='L')
    {
        for(int i=0;i<strlen(a);i++)
        for(int j=0;;j++)
        {
            if(a[i]==ans[j])
            {
            printf("%c",ans[j+1]);
            break;
            }
        }
    }
 printf("\n");
 return 0;   
}