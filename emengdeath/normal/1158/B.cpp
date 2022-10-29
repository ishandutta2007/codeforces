#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 3e6;
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    if (n == m) {
        while (n --)
        printf("1");
        return 0;
    }
    int x = (n - m) / 2;
    for (int i = 1; i <= n; i ++)
        if (i % (x + 1))
            printf("0");
        else printf("1");
    return 0;
}