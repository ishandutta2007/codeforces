#include <stdio.h>
#include <algorithm>

using namespace std;

int a,b,x,y;

int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}

int main() {
    scanf("%d %d %d %d", &a, &b, &x, &y);
    int g = gcd(x,y);
    x /= g;
    y /= g;
    
    int mult = min(a/x, b/y);
    printf("%d %d\n", x*mult, y*mult);
}