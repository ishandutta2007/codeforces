#include<cstdio>
#include<cstring>
using namespace std;
main()
{
    int n,p,no=0,ok=0,j;
    scanf("%d %d",&n,&p);
    p--;
    char s[10000];
    scanf("%s",s);
    int i;
    j=strlen(s)-1;
    while(1)
    {
        s[j]++;
        ok=1;
        for(i=j;i>=0;i--)
        {
            if(s[i]<='a'+p)
            break;
            else if(i!=0)
            {
                s[i]='a';
                s[i-1]++;
            }
            else
            no=1;
        }
        if(no)
        {
            printf("NO\n");
        break;
        }
        for(j=0;j<strlen(s);j++)
        {
            if(j<strlen(s)-1&&s[j]==s[j+1])
            {
            j++;
            ok=0;
            break;
            }
            if(j<strlen(s)-2&&s[j]==s[j+2])
            {
                j+=2;
                ok=0;
                break;
            }
        }
        if(ok)
        {
            printf("%s\n",s);
            break;
        }
    }
    return 0;
}