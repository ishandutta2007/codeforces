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
const int maxn = 1e5;
const int sg[] = {1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3 , 6, 11, 12, 14, 9, 3, 6};
int v[maxn], cnt, n, ans;
int main(){
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    if (!v[i]){
        int m = 0;
        for (long long j = i; j <= n; j *= i, m++)
        if (j < maxn) v[j] = 1;
        cnt = cnt + m;
        ans ^= sg[m - 1];
    }
    if (ans ^ ((n - cnt) & 1)) puts("Vasya"); else puts("Petya");
}