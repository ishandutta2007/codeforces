#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, a[100005];
int main(){
    scanf("%d", &n);
    if (n % 2 == 0){
        puts("-1");
        return 0;
    }
    a[n / 2] = 0;
    for (i = 0; i < n / 2; i++) a[i] = n - i * 2 - 1;
    for (i = n / 2 + 1; i < n; i++) a[i] = n - (i - n / 2 - 1) * 2 - 2;
    for (i = 0; i < n; i++) printf("%d ", i); puts("");
    for (i = 0; i < n; i++) printf("%d ", a[i]); puts("");
    for (i = 0; i < n; i++) printf("%d ", (i + a[i]) % n); puts("");
}