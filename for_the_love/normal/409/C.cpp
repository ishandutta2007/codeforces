#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)


const int N = 209;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;

const int a[] = {1, 1, 2, 7, 4};
int main(){
    int ans = 100, x;
    for (int i = 0; i < 5; i++){
        scanf("%d", &x);
        ans = min(ans, x / a[i]);
    }
    printf("%d\n", ans);
}