#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>

using namespace std;

int change[5005];
int n, m;
int Max[5005];
int oper[5005][4];

int main()
{
    scanf("%d%d", &n, &m);
    for(int j=1; j <= n; ++j)
        Max[j]=999999999;
    for(int i=0; i < m; ++i){
        int t, l, r, v;
        scanf("%d%d%d%d", &t, &l, &r, &v);
        oper[i][0]=t;
        oper[i][1]=l;
        oper[i][2]=r;
        oper[i][3]=v;
        if(t == 1){
            for(int j=l; j <= r; ++j)
                change[j] += v;
        }
        else{
            for(int j=l; j <= r; ++j)
                Max[j]=min(Max[j], v-change[j]);
        }
    }
    bool ok=1;
    for(int j=1; j <= n; ++j)
        change[j]=0;
    for(int i=0; i < m; ++i){
        int t, l, r, v;
        t=oper[i][0];
        l=oper[i][1];
        r=oper[i][2];
        v=oper[i][3];
        if(t == 1){
            for(int j=l; j <= r; ++j)
                change[j] += v;
        }
        else{
            bool any=0;
            for(int j=l; j <= r; ++j)
                if(Max[j]+change[j] == v)
                    any=1;
            if(!any)
                ok=0;
        }
    }
    if(!ok)
        printf("NO\n");
    else{
        printf("YES\n");
        for(int j=1; j <= n; ++j)
            printf("%d ", Max[j]);
    }
    return 0;
}