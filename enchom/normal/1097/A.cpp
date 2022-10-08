#include <iostream>
#include <stdio.h>
using namespace std;

char table[4];
char hand[6][4];

int main()
{
    int i;
    bool ans = false;

    scanf("%s",table);

    for (i=1;i<=5;i++)
    {
        scanf("%s",hand[i]);

        if (hand[i][0] == table[0])
            ans = true;
        if (hand[i][1] == table[1])
            ans = true;
    }

    if (ans)
        printf("YES\n");
    else
        printf("NO\n");
}