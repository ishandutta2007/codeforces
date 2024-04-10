#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

char fixedtext[15001];
Int ftL=0;

int main()
{
    char ch;
    Int i;
    bool lastwasspace=false;
    
    while(1)
    {
        scanf("%c",&ch);
        
        if (ch==10)
        break;
        
        if (ch==' ')
        {
            if (!lastwasspace)
            {
                lastwasspace=true;
                ftL++;
                fixedtext[ftL]=ch;
            }
        }
        else if (ch=='.' || ch==',' || ch=='!' || ch=='?')
        {
            if (lastwasspace)
            {
                fixedtext[ftL]=ch;
                ftL++;
                fixedtext[ftL]=' ';
            }
            else
            {
                ftL++;
                fixedtext[ftL]=ch;
                ftL++;
                fixedtext[ftL]=' ';
                lastwasspace=true;
            }
        }
        else
        {
            ftL++;
            fixedtext[ftL]=ch;
            lastwasspace=false;
        }
    }
    for (i=1;i<=ftL;i++)
    {
        printf("%c",fixedtext[i]);
    }
    printf("\n");
    return 0;
}