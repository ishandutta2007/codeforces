#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 999999999
using namespace std;

int a[100005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        scanf("%d", a+i);
    for(int i=30; i >= 0; --i){
        int j=(1<<i)-1;
        int tN=0;
        for(int k=0; k < n; ++k)
            if(a[k]&(1<<i)){
                j &= a[k];
                ++tN;
            }
        if(j)
            continue;
        printf("%d\n", tN);
        for(int k=0; k < n; ++k)
            if(a[k]&(1<<i))
                printf("%d ", a[k]);
        return 0;
    }
    return 0;
}