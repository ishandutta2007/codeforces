#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <cstring>
#define MAXN 500000

using namespace std;

int n, d;
bool possible[1000005];
int c[55];

int main()
{
    possible[0]=1;
    scanf("%d%d", &n, &d);
    for(int i=0; i < n; ++i)
        scanf("%d", c+i);
    for(int i=0; i < n; ++i)
        for(int j=MAXN; j >= 0; --j){
            if(possible[j])
                possible[j+c[i]]=true;
        }
    int days=0;
    int best=0;
    while(true){
        int newBest=best;
        for(int i=best+1; i <= best+d; ++i)
            if(possible[i])
                newBest=i;
        if(best == newBest)
            break;
        best=newBest;
        ++days;
    }
    printf("%d %d\n", best, days);
    return 0;
}