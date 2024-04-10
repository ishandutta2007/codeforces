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
const int INF = 1e9 + 7;
struct Pnode{
    int x, y;
} p1, p2;
int main(){
    int n;
    scanf("%d", &n);
    int mnx, mny, mxy, mxx, sum = 0;
    mxx = mxy = -INF;
    mnx = mny = INF;
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
        mxx = max(p2.x, mxx);
        mxy = max(p2.y, mxy);
        mnx = min(p1.x, mnx);
        mny = min(p1.y, mny);
        sum += (p2.x - p1.x) * (p2.y - p1.y);
    }
    if ((mxy - mny) == (mxx - mnx) && sum == (mxy - mny) * (mxx - mnx)) puts("YES"); else puts("NO");
}