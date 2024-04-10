#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
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
const int M = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int p = 0, last = 1;
    printf("%d", 1);
    for (int i = m; i >= 1; i--){
        if (!p) last += i; else last -= i; printf(" %d", last);
        p ^= 1;
    }
    for (int i = m + 2; i <= n; i++) printf(" %d", i);
}