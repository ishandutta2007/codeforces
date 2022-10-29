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


const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;




int main(){
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    while (a >= b){
        ans += a / b * b;
        a = a / b + a % b;
    }
    printf("%d\n", ans + a);
}