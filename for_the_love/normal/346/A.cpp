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

int n, g, a[105];


int gcd(int a, int b){if (!b) return a; return gcd(b, a % b);}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    g = gcd(a[1], a[2]);
    for (int i = 3; i <= n; i++) g = gcd(a[i], g);
    sort(a + 1, a + n + 1);
    if ((a[n] / g - n) % 2 == 0) puts("Bob"); else puts("Alice");
}