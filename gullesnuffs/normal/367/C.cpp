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

int q[100005], w[100005];
int getNumber(int n){
    if(n == 1)
        return 1;
    if(n%2){
        return (n*(n-1))/2+1;
    }
    return (n*n)/2;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i < m; ++i){
        scanf("%d%d", q+i, w+i);
    }
    sort(w, w+m);
    int N;
    for(N=1; N <= m && getNumber(N) <= n; ++N);
    --N;
    long long ans=0;
    for(int i=m-1; i >= m-N; --i)
        ans += w[i];
    printf("%I64d\n", ans);
    return 0;
}