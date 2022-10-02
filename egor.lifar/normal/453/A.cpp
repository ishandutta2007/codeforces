#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n;
int m;
double ans;


int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        ans += i * (pow(double(i) / double(m), double(n)) - pow(double(i - 1) / double(m), double(n)));
    }
    printf("%.10lf\n", ans);
    return 0;
}