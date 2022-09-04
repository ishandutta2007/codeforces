#include<stdio.h>
main()
{
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans++;
        if(s[i]!='1')
        break;
    }
    printf("%d\n",ans);
    return 0;
}