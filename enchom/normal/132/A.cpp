#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

char text[101];
Int tL=0;
Int bin[9];
Int PowerOf2[10];

void Binary(Int k)
{
    Int uk=8;
    while(k>0)
    {
        bin[uk]=k%2;
        uk--;
        k=k/2;
    }
    for (uk;uk>=1;uk--)
    bin[uk]=0;
}

Int EightBitReverse()
{
    Int i;
    Int thepower=0,num=0;
    for (i=1;i<=8;i++)
    {
        num=num+bin[i]*PowerOf2[thepower];
        thepower++;
    }
    return num;
}

int main()
{
    char ch;
    Int revnum;
    Int prevnum;
    Int ans;
    Int i;
    
    PowerOf2[0]=1;
    for (i=1;i<=9;i++)
    {
        PowerOf2[i]=PowerOf2[i-1]*2;
    }
    while(1)
    {
        scanf("%c",&ch);
        if (ch==10)
        break;
        else
        {
            tL++;
            text[tL]=ch;
        }
        
    }
    text[0]=0;
    for (i=1;i<=tL;i++)
    {
        Binary(text[i-1]);
        prevnum=EightBitReverse();
        Binary(text[i]);
        revnum=EightBitReverse();
        
        ans=prevnum-revnum;
        if (ans<0)
        ans+=256;
        
        printf("%I64d\n",ans);
    }
    return 0;
}