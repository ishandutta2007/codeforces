#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    int n, c, s = 0, no = 0;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&c);
        if(c > 1) {
            s ^= (c % 2);
            no++;
        }
        printf("%d\n",(s ^((no-1)%2)) ? 2 : 1);
    }
    return 0;
}