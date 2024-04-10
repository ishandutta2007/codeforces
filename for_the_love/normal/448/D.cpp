#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 5555;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int n, m;
LL Find(LL x){
    LL ret = 0;
    for (int i = 1; i <= n; i++)
        ret += min((LL)m, x / i);
    return ret;
}

int main(){

    LL k;
    scanf("%d%d%I64d", &n, &m, &k);
    LL l = 1, r = (LL)n * m, ans;
    while (l <= r){
        LL mid =  l + r >> 1;
        LL t = Find(mid);
        if (t >= k){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}