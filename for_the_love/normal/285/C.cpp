#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long ans, a[300005], n, i;
int main(){
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) ans += abs(a[i] - i);
    cout << ans;
}