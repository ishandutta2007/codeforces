#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    if (n > 0){
        printf("%d\n", max(n, max(n / 10, n / 100 * 10 + n % 10)));
    }else{
        n = -n;
        if (min(n, min(n / 10, n / 100 * 10 + n % 10)) == 0){
            printf("0\n");
        }else
        printf("-%d\n", min(n, min(n / 10, n / 100 * 10 + n % 10)));
    }

}