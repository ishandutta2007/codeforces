#include <cstdio>

int n;
int arr[1000005];

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;++i) arr[i]=i;
    int mul=1;
    while (n>3) {
        for (int i=1;i<=n;++i) if (arr[i]%2==1) printf("%d ", mul);
        for (int i=1;i<=n>>1;++i) arr[i]=arr[i*2]>>1;
        mul*=2; n>>=1;
    }if (n==1) printf("%d", mul);
    if (n==2) printf("%d %d", mul, mul*2);
    if (n==3) printf("%d %d %d", mul, mul, mul*3);
    return 0;
}