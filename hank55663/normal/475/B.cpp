#include<stdio.h>
main()
{
    int n,m;
    scanf("%d %d\n",&n,&m);
    char sh[20],ss[20];
    for(int i=0;i<n;i++)
    scanf("%c",&sh[i]);
    scanf("\n"); 
    for(int i=0;i<m;i++)
    scanf("%c",&ss[i]);
    if(sh[0]=='<'&&ss[0]=='^')
    {printf("NO\n");
    return 0;
    }
    if(sh[n-1]=='<'&&ss[0]=='v')
    {printf("NO\n");
    return 0;
    }
    if(sh[0]=='>'&&ss[m-1]=='^')
    {printf("NO\n");
    return 0;
    }
    if(sh[n-1]=='>'&&ss[m-1]=='v')
    {printf("NO\n");
    return 0;
    }
    printf("YES\n");
    return 0;
}