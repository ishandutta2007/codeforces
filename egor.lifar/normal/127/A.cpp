#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>
#include <cmath>

using namespace std;


int main()
{  
    int n, k;
    double x[1000], y[1000];
    double w = 0.00000000;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
      scanf("%lf %lf", &x[i], &y[i]);
    }
    for(int i = 0; i < n - 1; i++){
      w += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
    }
    w = ( w * k  ) / 50;
    printf("%lf", w);
    return 0;

}