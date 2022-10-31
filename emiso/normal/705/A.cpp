#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0; i<n-1; i++) {
        if(i & 1) printf("I love that ");
        else printf("I hate that ");
    }

    if(n & 1) printf("I hate it\n");
    else printf("I love it\n");

    return 0;
}