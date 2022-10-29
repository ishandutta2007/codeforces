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

int n, m, i;
int main(){
    scanf("%d%d", &n, &m);
    if (n * (n - 1) / 2 <= m) puts("no solution");
    else{
        for (i = 1; i <= n; i++) printf("%d %d\n", 0, i);
    }

}