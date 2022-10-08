#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int n;
char seq[2001];
Int L;

int main()
{
    Int i;
    Int juices=0;

    scanf("%I64d",&n);
    scanf("%s",seq);
    L=strlen(seq);

    for (i=3;i<L;i++)
    {
        if (seq[i-1]==seq[i-2] && seq[i-2]==seq[i-3])
        {
            if (i%n==0)
            {
                juices++;
            }
        }
    }

    printf("%I64d\n",juices);

    return 0;
}