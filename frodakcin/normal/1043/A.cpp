#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 110;
int a[MAXN], N;

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", a + i);
    int mxa = 0, sa = 0;
    for(int i = 0;i < N;i++) sa += a[i], mxa = max(mxa, a[i]);
    
    printf("%d\n", max((sa * 2 + N)/N, mxa));
    
    return 0;
}