#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int h, w, h1, w1;


int main() {
    scanf("%d:%d", &h, &w);
    scanf("%d:%d", &h1, &w1);
    int m = h * 60 + w, m1 = h1 * 60 + w1;
    if (m < m1) {
        m1 -= m;
        m = 24 * 60;
    }
    int ans = m - m1;
    printf("%.2d:%.2d\n", ans / 60, ans % 60);
    return 0;
}