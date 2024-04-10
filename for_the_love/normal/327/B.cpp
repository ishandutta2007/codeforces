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

int ans[100005], v[10000005], i, j, k, n;
int main(){
    scanf("%d", &n);
    j = 2;
    for (i = 1; i <= n; i++){
        while (v[j]) j++;
        for (k = j; k <= 10000000; k+=j) v[k] = 1;
        ans[i] = j;
    }
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
}