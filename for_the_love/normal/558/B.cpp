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
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, x, ans = 0;
int cnt[N], l[N], r[N];


int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (!l[x]) l[x] = i;
        r[x] = i;
        cnt[x]++;
        ans = max(ans, cnt[x]);
    }

    int res = INF;
    PI p;
    for (int i = 1; i <= 1000000; i++)
    if (cnt[i] == ans){
        if (r[i] - l[i] < res){
            res = r[i] - l[i];
            p = make_pair(l[i], r[i]);
        }
    }
    printf("%d %d\n", p.first, p.second);
}