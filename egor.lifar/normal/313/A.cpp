

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int main() {
   int a;
   scanf("%d", &a);
   int x;
   x = max(a, a / 10);
   x = max(x, a/ 100 * 10 + a % 10);
   printf("%d", x);




 }