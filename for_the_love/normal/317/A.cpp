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

long long x, y, m, a[100];
unsigned long long b[100];
long long cmp(long long a, long long b){return a > b;}
long long cmp2(unsigned long long a, unsigned long long b){return a > b;}
int main(){
    cin >> a[1] >> a[2] >> m;
    if (a[1] >= m || a[2] >= m){
        puts("0");
        return 0;
    }
    if (a[1] <= 0 && a[2] <= 0){
        puts("-1");
        return 0;
    }
    sort(a + 1, a + 3, cmp);
    long long ans = 0;
    if (a[2] < 0) ans = -a[2] / a[1];
    a[2] = a[2] + ans * a[1];
    while (1){
        ans++;
        a[3] = a[1] + a[2];
        sort(a + 1, a + 4, cmp);
        if (a[1] >= m) break;
    }
    cout << ans << endl;
}