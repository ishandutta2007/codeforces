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

int n, t, v[100005], ans[100005];
int main(){
    scanf("%d", &n);
    if (n % 2){
        puts("-1");
        return 0;
    }
    t = 0; ans[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        if (t % 2 == 0){
            if (!v[(t + n) / 2]) t = (t + n) / 2;
            else t = t / 2;
            v[t] = 1;
        }else{
            if (!v[(t + n) / 2]) t = (t + n) / 2;
            else t = t / 2;
            v[t] = 1;
        }
        ans[i] = t;
    }
    for (int i = 0; i <= n; i++) printf("%d ", ans[i]);
}