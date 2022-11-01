#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n, h, m;
    scanf("%d %d:%d",&n, &h, &m);

    if(n == 12) {
        if(h == 0) h = 1;
        else if(h > 12) {
            if (h % 10 > 0) h = h % 10;
            else h = 10;
        }
    }
    else {
        if(h > 23) {
            h = 10 + (h % 10);
        }
    }

    if(m >= 60) m = 10 + (m % 10);

    if(h < 10) printf("0");
    printf("%d:",h);
    if(m < 10) printf("0");
    printf("%d\n",m);

    return 0;
}