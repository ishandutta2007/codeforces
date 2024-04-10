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

const double pi = 3.141592653589793;
int main(){
    int n, R, r;
    scanf("%d%d%d", &n, &R, &r);
    if (r > R){
        puts("NO");
        return 0;
    }
    if (2 * r > R){
        if (n == 1) puts("YES"); else puts("NO");
        return 0;
    }
    double cosa = (2.0 * (R - r) * (R - r) - 4.0 * r * r) / 2.0 / (R - r) / (R - r);
    double t = acos(cosa);
    int num = (int)(2 * pi / t + 1e-6);
    if (num < n) puts("NO"); else puts("YES");
}