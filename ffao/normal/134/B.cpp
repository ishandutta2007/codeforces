#include <stdio.h> 
#include <algorithm>

using namespace std;

int num;

int gcd(int a, int b) {
    if (b == 0) return (a==1)?-1:1000000000;
    else return gcd(b,a%b) + a/b;
}

int main() {
    scanf("%d", &num);
    int b = 1000000000;
    for (int i = 1; i <= num; i++) {
        b = min(b, gcd(num,i));
    }
    printf("%d\n", b);
}