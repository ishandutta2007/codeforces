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

int occur[25];
int t[100005];
bool needed[3000000];

int popcount(int n){
    int m=0;
    for(int i=0; i < 20; ++i)
        if(n&(1<<i))
            ++m;
    return m;
}

int main()
{
    int d, n, m;
    scanf("%d%d%d", &n, &m, &d);
    for(int i=0; i < 3000000; ++i)
        needed[i]=0;
    for(int i=0; i < m; ++i){
        int sz;
        scanf("%d", &sz);
        for(int j=0; j < sz; ++j){
            int a;
            scanf("%d", &a);
            t[a]=i;
        }
        occur[i]=0;
    }
    int b=0;
    for(int i=1; i < d; ++i){
        ++occur[t[i]];
        b |= (1<<t[i]);
    }
    for(int i=d; i <= n; ++i){
        ++occur[t[i]];
        b |= (1<<t[i]);
        needed[b]=1;
        --occur[t[i-d+1]];
        if(!occur[t[i-d+1]])
            b ^= (1<<t[i-d+1]);
    }
    needed[(1<<m)-1]=1;
    for(int i=0; i < (1<<m); ++i){
        if(!needed[i])
            continue;
        for(int j=0; j < m; ++j){
            needed[i|(1<<j)]=1;
        }
    }
    int bestN=0;
    for(int i=(1<<m)-1; i >= 0; --i){
        if(!needed[i] && popcount(i) > bestN){
            bestN=popcount(i);
        }
    }
    printf("%d\n", m-bestN);
    return 0;
}