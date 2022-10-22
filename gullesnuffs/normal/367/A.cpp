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
#define MAXP 1000

using namespace std;

char input[100005];
int n[100005][3];

int main()
{
    scanf("%s", input);
    n[0][0]=0;n[0][1]=0;n[0][2]=0;
    for(int i=0; input[i]; ++i){
        for(int j=0; j < 3; ++j){
            n[i+1][j]=n[i][j];
            if(input[i] == 'x'+j)
                ++n[i+1][j];
        }
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i < m; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        int a[3];
        int Max=0;
        for(int j=0; j < 3; ++j){
            a[j]=n[r+1][j]-n[l][j];
            if(a[j] > Max)
                Max=a[j];
        }
        bool ok=1;
        for(int j=0; j < 3; ++j)
            if(a[j] < Max-1)
                ok=0;
        if(r-l <= 1)
            ok=1;
        puts(ok?"YES":"NO");
    }
    return 0;
}