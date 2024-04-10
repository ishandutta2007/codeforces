#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int ans = 0;
char str[1011];
int n;

int MAX(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}

bool notPali(int L,int R)
{
    int i;
    int rp = R;

    for (i=L;i<=R;i++)
    {
        if (str[i] != str[rp])
            return true;

        rp--;
    }

    return false;
}

int main()
{
    int i,j;

    scanf("%s",str+1);
    n=strlen(str+1);

    for (i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            if (notPali(i,j))
            {
                ans = MAX(ans,j-i+1);
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}