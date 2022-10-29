#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int a, b; scanf("%d%d", &a, &b);
    int x = floor(sqrt(a));
    printf("%s", x * (x + 1) <= b ? "Vladik" : "Valera");
    return 0;
}