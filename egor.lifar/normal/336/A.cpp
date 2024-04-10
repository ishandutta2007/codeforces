#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int z = abs(x) + abs(y);
    if(x < 0){
        printf("-%d 0", z);
        if(y < 0){
            printf(" 0 -%d", z);
        } else {
            printf(" 0 %d", z);
        }
    } else {
        if(y < 0){
          printf(" 0 -%d", z);
        }else {
          printf(" 0 %d", z);
        }
        printf(" %d 0", z);
    }



    return 0;
}