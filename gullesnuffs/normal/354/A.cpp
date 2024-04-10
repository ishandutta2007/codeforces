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
int w[100005];

int main() {
    int n, l, r, ql, qr;
    scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
    int s=0;
    for(int i=0; i < n; ++i){
        scanf("%d", w+i);
        s += w[i];
    }
    long long lSum=0, rSum=s;
    long long ans=999999999999LL;
    for(int i=0; i <= n; ++i){
        int lLen=i, rLen=n-i;
        long long cost=0;
        if(rLen > lLen)
            cost += (rLen-lLen-1)*qr;
        else if(lLen > rLen)
            cost += (lLen-rLen-1)*ql;
        cost += lSum*l;
        cost += rSum*r;
        if(cost < ans)
            ans=cost;
        if(i < n){
            lSum += w[i];
            rSum -= w[i];
        }
    }
    printf("%I64d\n", ans);
    return 0;
}