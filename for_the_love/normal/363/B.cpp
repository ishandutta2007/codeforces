//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5e5 + 5;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int s[N];

int main(){
    //freopen("in.txt", "r", stdin);
    int n, m, po;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    int ans = INF;

    for (int i = m; i <= n; i++)
    if (s[i] - s[i - m] < ans){
        ans = s[i] - s[i - m];
        po = i - m + 1;
    }
    printf("%d\n", po);
}