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

using namespace std;

int n;
long long a[100005];

int main(){
    scanf("%d",&n);
    for(int i=0; i < n; ++i)
        scanf("%I64d", a+i);
    sort(a, a+n);
    long long ans=0;
    long long removed=0;
    long long Min=0;
    for(int i=1; i < n; ++i){
        if((a[n-1]-removed)*(i-1) >= (a[0]-Min)*i){
            ans += a[n-1]-removed;
            removed=a[n-1];
            break;
        }
        ans += (a[i]-a[i-1])*i;
        Min += (a[i]-a[i-1])*(i-1);
        removed += (a[i]-a[i-1])*i;

    }
    ans += ((a[n-1]-removed)*n+n-2)/(n-1);
    printf("%I64d\n", ans);
    return 0;
}