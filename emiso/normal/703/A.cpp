#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    int n,m,c,mr=0,cr=0;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d %d",&m,&c);
        if(m > c) mr++;
        else if(c > m) cr++;
    }

    if(mr > cr) printf("Mishka\n");
    else if(cr > mr) printf("Chris\n");
    else printf("Friendship is magic!^^\n");

    return 0;
}