#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int chosen[100001];
int n;
char inp[100001];

int main()
{
    int i,j;
    int L;
    int let;

    memset(chosen,0,sizeof(chosen));

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",inp+1);
        L=strlen(inp+1);

        for (j=1;j<=L;j++)
        {
            if (inp[j]!='?')
            {
                let=(int)inp[j];

                if (chosen[j]==-1)
                {
                    continue;
                }
                else if (chosen[j]==0)
                {
                    chosen[j]=let;
                }
                else if (chosen[j]!=let)
                {
                    chosen[j]=-1;
                }
            }
        }
    }

    for (i=1;i<=L;i++)
    {
        if (chosen[i]==-1)
        printf("?");
        else if (chosen[i]==0)
        printf("a");
        else
        {
            printf("%c",(char)(chosen[i]));
        }
    }
    printf("\n");

    return 0;
}