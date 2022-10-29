#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define mid ((L + R) >> 1)
using namespace std;
int main(){
    int n , m , k;
    scanf("%d %d %d", &n, &m, &k);
    if (n > m || n > k ) printf("No");
    else
        printf("Yes");
    return 0;
}