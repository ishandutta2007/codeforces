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


int a[100005], n, ans[100005], cnt;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 30; i >= 0; i--){
        long long now = (1 << 31) - 1;
        for (int j = 1; j <= n; j++)
        if ((a[j] & (1 << i)) == (1 << i)) now &= a[j];

        if (now % (1 << i) == 0){
            for (int j = 1; j <= n; j++)
            if ((a[j] & (1 << i)) == (1 << i)) ans[++cnt] = a[j];
            break;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
}