#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int c[2][2];

int main(){
    int n, a, b, suma = 0, sumb = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a, &b);
        c[a & 1][b & 1] = 1;
        suma += a;
        sumb += b;
    }
    if (suma % 2 == 0 && sumb % 2 == 0) puts("0");
    else if (suma % 2 == 1 && sumb % 2 == 1){
        if (c[0][1] || c[1][0]) puts("1"); else puts("-1");
    }else puts("-1");
}