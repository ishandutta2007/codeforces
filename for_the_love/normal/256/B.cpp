#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long x, y, n, c, ux, dx, ly, ry, t, ans;
long long s(long long x){
    return x * x;
}
long long calc(long long x){
    return (1 + x) * x / 2;
}
int main(){
    cin >> n >> x >> y >> c;
    ux = dx = x;
    ly = ry = y;
    while (1){
        t = s((ux - dx) / 2 + 1) + s((ux - dx) / 2);
        if (ux > n) t -= s(ux - n);
        if (dx < 1) t -= s(1 - dx);
        if (ly < 1) t -= s(1 - ly);
        if (ry > n) t -= s(ry - n);
        if (ux - n > n - y + 1) t += calc(ux - n - (n - y + 1));
        if (1 - dx > n - y + 1) t += calc(1 - dx - (n - y + 1));
        if (ux - n > y) t += calc(ux - n - y);
        if (1 - dx > y) t += calc(1 - dx - y);
        if (t >= c) break;
        ans++;
        ux++; dx--;
        ly--; ry++;
    }
    cout << ans << endl;
}