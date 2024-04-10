#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
    int n;
    scanf("%d",&n);

    char a[100005][20];
    int i,j,s[20],k;
    for(i=0;i<n;i++)
    scanf("%s",a[i]);
    for(i=0;i<strlen(a[0]);i++)
    {
        if(a[0][i]=='?')
        {
            if(i==0)
            a[0][i]='1';
            else
            a[0][i]='0';
        }
    }   
    for(i=1;i<n;i++)
    {
        int start=-1;   
        if(strlen(a[i])<strlen(a[i-1])) 
        {
            printf("NO\n");
            return 0;
        }
        else if(strlen(a[i])==strlen(a[i-1]))
        {
            int ok=0,l=0;
            memset(s,-1,20*sizeof(int));
            for(j=0;j<strlen(a[i]);j++)
            {
                if(a[i][j]=='?')
                {
                    if(ok)
                    a[i][j]='0';
                    else
                    {
                        s[l]=j;
                        l++;
                        } 
                }
                else if(a[i][j]>a[i-1][j]&&ok!=-1)
                {
                    ok=1;
                    if(start==-1) 
                    start=j;
                    } 
                else if(a[i][j]<a[i-1][j]&&!ok)
                {
                    if(s[0]==-1)
                    {
                    printf("NO\n");
                    return 0;
                    }
                    else if(start==-1)
                    start=l-1;
                    ok=-1;
                }
                
            }
            if(ok==1)
            {
                
                for(l=0;s[l]!=-1&&s[l]<start;l++)
                a[i][s[l]]=a[i-1][s[l]];
                for(;s[l]!=-1;l++)
                a[i][s[l]]='0';
            }
            else
            {
                char num[20];
                memset(num,'0',20*sizeof(char));
                for(l=0;s[l]!=-1&&(l<=start||start==-1);l++)
                num[l]=a[i-1][s[l]];
                num[--l]++;
                for(;num[l]>'9';l--)
                {
                    if(l==0)
                    {
                    printf("NO\n");
                    return 0;
                    }
                    num[l]='0';
                    num[l-1]++;
                }
                for(l=0;s[l]!=-1;l++)
                {
                    a[i][s[l]]=num[l];
                }
            }
        }
        else
        {
            for(j=0;j<strlen(a[i]);j++)
            {
                if(a[i][j]=='?')
                {
                    if(j!=0)
                        a[i][j]='0';
                    else
                        a[i][j]='1';
                } 
            }
        }
    }
    printf("YES\n");
    for(i=0;i<n;i++)
    printf("%s\n",a[i]);
    return 0;
}