#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);

    if(n % 2 == 0) {
        printf("%d\n", n / 2);
        for(int i=0;i<n;i+=2) printf("2 ");
        printf("\n");
    }

    else {
        printf("%d\n", n / 2);
        for(int i=4;i<n;i+=2) printf("2 ");
        printf("3\n");
    }
    return 0;
}