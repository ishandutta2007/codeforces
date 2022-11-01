#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

int a, b;

int cmp(double x, double y = 0) {
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

int main() {
    scanf("%d %d", &a, &b);
    int c = cmp(b * log(a), a * log(b));
    if(c == 0) printf("=\n");
    else if(c < 0) printf("<\n");
    else printf(">\n");
    return 0;
}