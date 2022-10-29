#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
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
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Pnode{
    int x, y;
} p[N];


bool cmp(Pnode a, Pnode b){
    return a.x < b.x;
}

int n, d;
int main(){
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + n + 1, cmp);
    LL sum = 0, ans = 0;
    int r = 1;
    for (int i = 1; i <= n; i++){
        while (r <= n && p[r].x - p[i].x < d){
            sum += p[r].y;
            r++;
        }
        ans = max(ans, sum);
        sum -= p[i].y;
    }
    printf("%I64d\n", ans);
}