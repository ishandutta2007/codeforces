#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int genres[100001];
Int gL=0;
Int genrestress[100001];

int main()
{
    Int n,k;
    Int i,j;
    Int maxgood=-1;
    Int maxgoodgenre;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=0;i<=100000;i++)
    genrestress[i]=0;
    
    scanf("%I64d",&genres[1]);
    gL=1;
    
    for (i=2;i<=n;i++)
    {
        gL++;
        scanf("%I64d",&genres[gL]);
        if (genres[gL]==genres[gL-1])
        {
            gL--;
        }
    }
    for (i=1;i<=gL;i++)
    {
        if (i!=1 && i!=gL)
        {
            if (genres[i-1]==genres[i+1])
            genrestress[ genres[i] ]+=2;
            else
            genrestress[ genres[i] ]++;
        }
        else
        {
            genrestress[ genres[i] ]++;
        }
    }
    for (i=1;i<=k;i++)
    {
        if (maxgood<genrestress[i])
        {
            maxgood=genrestress[i];
            maxgoodgenre=i;
        }
    }
    printf("%I64d\n",maxgoodgenre);
    return 0;
}