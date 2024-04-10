#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int r, g, b, k = 0,n = 0, m = 0;
    scanf("%d %d %d", &r, &g, &b);
    int l = 30;
    while(k < r || n < g || m < b){
        if(l % 3 == 0){
            k += 2;
        }
        if(l % 3 == 1){
            n += 2;
        }
        if(l % 3 == 2){
            m += 2;
        }
        l++;
    }
    printf("%d\n", l - 1);
    return 0;
}