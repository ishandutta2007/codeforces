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

long long m;
double r, ans;
double calc(long long x){
    if (!x) return 0;
    double ret = 2 * r + sqrt(2) * r;
    if (x == 1) return ret;
    x--;
    return ret + (x + 1) * x * r + sqrt(2) * r * x * 2;
}
int main(){
    cin >> m >> r;
    for (int i = 1; i <= m; i++)
        ans += calc(i - 1) + calc(m - i) + 2 * r;
    ans /= m * m;
    printf("%.8lf\n", ans);
}