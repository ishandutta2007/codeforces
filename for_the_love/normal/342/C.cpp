#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int r, h, ans;
int main(){
    scanf("%d%d", &r, &h);
    ans = h / r * 2;
    h %= r;
    if (2 * h >= r){
        ans += 2;
        if (sqrt(3) * r <= 2 * h) ans++;
    }else ans++;
    printf("%d\n", ans);
}