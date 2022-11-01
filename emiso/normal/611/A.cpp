#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main()
{
    string day, of, wm;
    cin >> day >> of >> wm;
    if(wm == "week") {
        if(day == "6" || day == "5") printf("53\n");
        else printf("52\n");
    }
    else {
        if(day == "31") printf("7\n");
        else if(day == "30") printf("11\n");
        else printf("12\n");
    }
    return 0;
}