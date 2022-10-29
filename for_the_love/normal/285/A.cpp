#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, i;
int main(){
    scanf("%d%d", &n, &k);
    for (i = 1; i <= k + 1; i++) printf("%d ", k - i + 2);
    for (i = k + 2; i <= n; i++) printf("%d ", i);
}