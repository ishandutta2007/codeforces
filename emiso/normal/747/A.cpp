#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        int a = int(sqrt(n)) - i;
        if(n % a == 0) {
            printf("%d %d\n", a, n / a);
            return 0;
        }
    }
    return 0;
}