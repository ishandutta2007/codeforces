#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
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
    int n, m;
    scanf("%d%d", &n, &m);

    int ans = 1, mx = -1;
    if (m > 1){
        if (m - 1 > mx){
            mx = m - 1;
            ans = m - 1;
        }
    }
    if (m + 1 <= n){
        if (n - m > mx){
            mx = n - m;
            ans = m + 1;
        }
    }
    printf("%d\n", ans);
}