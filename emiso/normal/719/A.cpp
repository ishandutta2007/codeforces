#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int a[100];

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    if(n == 1) {
        if(a[0] == 0) printf("UP\n");
        else if(a[0] == 15) printf("DOWN\n");
        else printf("-1\n");
    }

    else {
        if(a[n-1] == 0) {
            printf("UP\n");
        }
        else if(a[n-1] == 15) {
            printf("DOWN\n");
        }
        else {
            if(a[n-2] > a[n-1])
                printf("DOWN\n");
            else printf("UP\n");
        }
    }

    return 0;
}