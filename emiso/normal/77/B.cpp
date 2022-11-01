#include <bits/stdc++.h>

using namespace std;

int t;
double a, b;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lf %lf", &a, &b);

        double ar = a * b;
        if(b == 0) {
            printf("1\n");
            continue;
        }

        if(a == 0) {
            printf("0.5\n");
            continue;
        }

        else if(b < a / 4) {
            ar += (b * b * 2);
            ar += (a - b*4) * b;
        }

        else {
            ar += a * a / 8;
        }

        printf("%.9f\n", ar / (2 * a * b));
    }
    return 0;
}