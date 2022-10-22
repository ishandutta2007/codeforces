#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <cassert>
#include <map>
#define MOD 1000000007LL
#define INF 999999999
#define PI 3.14159265358

using namespace std;

int a[500005];
int ev[1000005];
int segs[1000005];

int main() {
    int n, k;
    int minA=1000000;
    scanf("%d%d", &n, &k);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
        if(a[i] < minA)
            minA=a[i];
        ++ev[max(0, a[i]-k)];
        --ev[a[i]+1];
    }
    segs[0]=0;
    for(int i=0; i <= 1000000; ++i){
        if(i)
            segs[i]=segs[i-1];
        segs[i] += ev[i];
    }
    int ans=0;
    for(int g=1; g <= minA; ++g){
        int s=0;
        for(int G=g; G <= 1000000; G += g)
            s += segs[G];
        if(s >= n)
            ans=g;
    }
    printf("%d\n", ans);
    return 0;
}