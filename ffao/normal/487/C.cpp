#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
int r[1100000];
int ma[1100000];

int main() {
    scanf("%d", &n);
    if (n == 4) {
        printf("YES\n1\n3\n2\n4");
        return 0;
    }
    
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            printf("NO\n");
            return 0;
        }
    }
   

    int m=n;
    r[1] = 1; 
    for (int i=2; i<m; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;

    printf("YES\n");
    printf("1\n");

    for (long long i = 2; i <= n; i++) {
        int next = (int)((i * r[i-1]) % n);
        printf("%d\n", next == 0 ? n : next);
    }
}