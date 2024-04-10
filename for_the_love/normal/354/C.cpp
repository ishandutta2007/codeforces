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
const int N = 22;


int s[2222222], c[2222222];

int main(){
    int n, k, x;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        c[x]++;
    }
    for (int i = 1; i <= 1e6 + 1e6; i++) s[i] = s[i - 1] + c[i];
    for (int i = 1e6; i >= 1; i--){
        if (s[i - 1]) continue;
        int flag = 0;
        for (int j = 1; j * i <= 1e6; j++)
        if (s[i * (j + 1) - 1] - s[j * i + k] > 0) flag = 1;
        if (flag) continue;
        printf("%d\n", i);
        break;
    }
}