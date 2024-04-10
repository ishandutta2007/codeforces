#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

bool isp(int n) {
    for(int i=2;i*i<=n;i++)
        if(n % i == 0) return false;
    return true;
}

int main() {
    int n;
    scanf("%d",&n);

    if(n == 2) printf("1");
    else if(n == 3) printf("1");
    else if(n == 4) printf("2");
    else if(n == 5) printf("1");
    else if(isp(n)) printf("1");
    else if(n % 2 == 0) printf("2");
    else if(isp(n - 2)) printf("2");
    else printf("3");

    printf("\n");
    return 0;
}