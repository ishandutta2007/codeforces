#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int a, c;
long long int b = 0;

int main() {
    scanf("%d %d", &a, &c);
    
    long long int pow_3 = 1;
    
    while (a || c) {
        int da = a%3, dc = c%3;
        a /= 3;
        c /= 3;
        
        b += pow_3 * ((dc-da+3) % 3);
        
        pow_3 *= 3;
    }
    
    printf("%lld\n", b);
}