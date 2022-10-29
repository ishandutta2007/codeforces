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

int n, i, t, a[2000005];
long long ans;
int cmp(int a, int b){return a > b;}
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    while(1){
        if (!n) break;
        for (i = 1; i <= n; i++) ans += a[i];
        n /= 4;
    }
    cout << ans << endl;

}