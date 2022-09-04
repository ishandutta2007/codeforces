#include<stdio.h>
#include<string.h>
main()
{
    char a[1000005];
    long long int ans[1000005];
    long long int x,y,i,sum=0,sum2=1,j,k,length;
    scanf("%s",a);
    length=strlen(a);
    for(i=0;i<length;i++)
    a[i]=a[i]-'0';
    scanf("%I64d %I64d",&x,&y);
    for(i=length-1;i>0;i--)
    {
        sum=(sum+sum2*a[i])%y;
        sum2=sum2*10%y;
        ans[i]=sum;
    }
    sum=0;
    for(i=0;i<length;i++) 
    {
        sum=(sum*10+a[i])%x;
        if(sum==0&&ans[i+1]==0&&a[i+1]!=0)
        break;
    }
    if(i<length-1)
    {
        printf("YES\n");
        for(k=0;k<=i;k++)
        printf("%c",a[k]+'0');
        printf("\n");
        for(;k<length;k++)
        printf("%c",a[k]+'0');
    }
    else
    printf("NO\n");
    return 0;
}