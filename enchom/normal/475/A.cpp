#include <iostream>
#include <stdio.h>
using namespace std;

char bus[27][27]={
'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+','.',
'|','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','|','D','|',')',
'|','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','|','.','|','.',
'|','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','|','.',
'|','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','|','.','|',')',
'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+','.'
};

void PushPassenger()
{
    int i,j;

    for (i=0;i<=26;i++)
    {
        for (j=0;j<=5;j++)
        {
            if (bus[j][i]=='#')
            {
                bus[j][i]='O';
                return;
            }
        }
    }

    return;
}


int main()
{
    int k;
    int i,j;

    scanf("%d",&k);

    for (i=1;i<=k;i++)
    {
        PushPassenger();
    }

    for (i=0;i<=5;i++)
    {
        for (j=0;j<=26;j++)
        {
            if (j==26 && (i==0 || i==2 || i==3 || i==5))
            continue;

            printf("%c",bus[i][j]);
        }
        if (i!=5)
        printf("\n");
    }

    return 0;
}