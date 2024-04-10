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
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

long long M, ans;
void dfs(int x, int l, long long n, long long m){
    if (m > M || n > ans || x >= 15) return;
    if (m == M) ans = min(ans, n);
    for (int i = 1; i <= l; i++){
        if (n > ans / p[x] + 1) return;
        dfs(x + 1, i, n *= p[x], m * (i + 1));
    }
}
int main(){
    cin >> M;
    ans = 1e18;
    dfs(0, 62, 1, 1);
    cout << ans << endl;
}