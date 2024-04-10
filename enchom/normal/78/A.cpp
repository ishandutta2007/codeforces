#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

bool Vowel(char ch)
{
    if (ch=='a' || ch=='u' || ch=='i' || ch=='o' || ch=='e')
    return true;
    else
    return false;
}

int main()
{
    Int i;
    char ch;
    Int thevowels[4];
    
    for (i=1;i<=3;i++)
    {
        thevowels[i]=0;
        while(1)
        {
            scanf("%c",&ch);
            
            if (ch==10)
            break;
            
            if (Vowel(ch))
            thevowels[i]++;
        }
    }
    if (thevowels[1]==5 && thevowels[2]==7 && thevowels[3]==5)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}