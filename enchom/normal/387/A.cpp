#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int wake_min,wake_hour;
int sleep_min,sleep_hour;
char inp[10];
int L;

int INT(char ch)
{
    return ch-'0';
}

void Print(int a)
{
    if (a<10)
    printf("0");

    printf("%d",a);

    return;
}

int main()
{
    int gotobed_min,gotobed_hour;

    scanf("%s",inp);
    L=strlen(inp);

    wake_hour=INT(inp[0])*10+INT(inp[1]);
    wake_min=INT(inp[3])*10+INT(inp[4]);

    ///

    scanf("%s",inp);
    L=strlen(inp);

    sleep_hour=INT(inp[0])*10+INT(inp[1]);
    sleep_min=INT(inp[3])*10+INT(inp[4]);

    ///

    gotobed_min=wake_min-sleep_min;
    gotobed_hour=wake_hour-sleep_hour;

    if (gotobed_min<0)
    {
        gotobed_min+=60;
        gotobed_hour--;
    }

    if (gotobed_hour<0)
    {
        gotobed_hour+=24;
    }

    Print(gotobed_hour);
    printf(":");
    Print(gotobed_min);
    printf("\n");

    return 0;
}