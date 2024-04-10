#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int main(){
    int n, x, y, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        if (x + 2 <= y) ans++;
    }
    printf("%d\n", ans);
}