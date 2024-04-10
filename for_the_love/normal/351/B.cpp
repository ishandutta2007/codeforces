#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[3333];

int main(){
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j < n - i + 1; j++)
    if (a[j] > a[j + 1]) ans++, swap(a[j], a[j + 1]);
    printf("%d\n", ans / 2 * 4 + ans % 2);
}