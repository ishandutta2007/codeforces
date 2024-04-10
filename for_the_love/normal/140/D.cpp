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

int n, a[105];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int sum = 10, tot = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    if (sum + a[i] <= 720){
        sum += a[i];
        ans++;
        if (sum > 360) tot += sum - 360;
    }
    printf("%d %d\n", ans, tot);
}