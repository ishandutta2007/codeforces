
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
    int n;
    scanf("%d", &n);
    if(n % 2 == 1){
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= n / 2; i++){
        printf("%d %d ", i * 2, i * 2 - 1);
    }
    printf("\n");
    return 0;
}