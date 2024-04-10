#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <complex>
#include <cassert>
using namespace std;

int a[1000005];
int composite[10000005];
int num[10000005];
int sum[10000005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i< n; ++i)
        scanf("%d", a+i);
    composite[0]=1;
    composite[1]=1;
    for(int i=2; i <= 10000000; ++i){
        if(composite[i]){
            continue;
        }
        composite[i]=i;
        for(int j=2*i; j <= 10000000; j += i)
            composite[j]=i;
    }
    for(int i=0; i < n; ++i){
        int j=a[i];
        int last=0;
        while(j != 1){
            if(composite[j] != last)
                ++num[composite[j]];
            last=composite[j];
            j /= last;
        }
    }
    for(int i=1; i <= 10000002; ++i)
        sum[i]=sum[i-1]+num[i];
    int m;
    scanf("%d", &m);
    for(int i=0; i < m; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        if(r > 10000000)
            r=10000000;
        if(l > 10000000)
            l=10000000;
        printf("%d\n", sum[r]-sum[l-1]);
    }
    return 0;
}