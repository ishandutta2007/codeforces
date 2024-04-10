
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
 
// #define MAXN  500000
 
// vector <int> v[MAXN];
int main()
{
    int n, x[100000], y[100000];
    scanf("%d", &n);
    int a = 1000000001, b = -1000000001;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x[i], &y[i]);
        a = min(a, x[i]);
        b = max(b, y[i]);
    }
    for(int i = 0; i < n; i++){
        if(x[i] <= a && y[i] >= b){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}