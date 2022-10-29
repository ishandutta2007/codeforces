#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int xx1, xx2, yy1, yy2;
int main(){
    scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
    if (xx1 == xx2){
        printf("%d %d %d %d\n", yy1 - yy2 + xx1, yy1, yy1 - yy2 + xx1, yy2);
    }else if (yy1 == yy2){
        printf("%d %d %d %d\n", xx1, xx1 - xx2 + yy1, xx2, xx1 - xx2 + yy2);
    }else if (abs(xx1 - xx2) == abs(yy1 - yy2)){
        printf("%d %d %d %d\n", xx1, yy2, xx2, yy1);
    }else puts("-1");
}