#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL

int n;
char dna[100011];
int seen[1001];

int main()
{
    int i;
    Int solutions=1;
    int maxcounter=0;
    int themax=0;

    scanf("%d",&n);
    scanf("%s",dna+1);

    for (i=1;i<=n;i++)
    {
        seen[ dna[i] ]++;

        if (seen[ dna[i] ]>themax)
        themax=seen[ dna[i] ];
    }

    if (seen['A']==themax) maxcounter++;
    if (seen['C']==themax) maxcounter++;
    if (seen['G']==themax) maxcounter++;
    if (seen['T']==themax) maxcounter++;

    for (i=1;i<=n;i++)
    {
        solutions*=(Int)maxcounter;
        solutions%=MOD;
    }

    printf("%lld\n",solutions);

    return 0;
}