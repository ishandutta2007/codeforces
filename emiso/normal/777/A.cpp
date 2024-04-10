#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, x, pos;

int main() {
    scanf("%d %d", &n, &x);

    for(int i = (n%6); i >= 1; i--) {
        if(i % 2) {
            if(x == 0) x = 1;
            else if(x == 1) x = 0;
        }

        else {
            if(x == 1) x = 2;
            else if(x == 2) x = 1;
        }
    }

    printf("%d\n", x);

    return 0;
}