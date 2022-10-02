#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


int main() {
    int h;
    double m;
    scanf("%d:%lf", &h, &m);
    h = h % 12;
    double h1 = h;
    double l1, l2;
    l2 = m * 6;
    l1 = h1 * 30 + 0.5 * m;
    printf("%.10lf %.10lf\n", l1, l2);
    return 0;
}