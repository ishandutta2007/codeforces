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
    int n;
    int a[100000];
    scanf("%d", &n);
    int b, c, t;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    b = 0;
    c = 1;
    t = abs(a[1] - a[0]);
    for(int i = 0; i < n; i++){
        if(t > abs(a[i] - a[(i + 1) % n])){
            b = i;
            t = abs(a[i] - a[(i + 1) % n]);
            c = (i + 1) % n;
        }
    }
    printf("%d %d\n", b + 1 , c + 1);
    return 0;
}