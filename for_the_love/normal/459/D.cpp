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

int n, a[N], t[N], b[N];


map <int, int> S;

inline int lowbit(int x){return x & -x;}

void Add(int x, int d){
    for (; x <= n; x += lowbit(x)) b[x] += d;
}
int Query(int x){
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += b[x];
    return ret;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--){
        S[a[i]]++;
        t[i] = S[a[i]];
        Add(t[i], 1);
    }
    S.clear();
    LL ans = 0;
    for (int i = 1; i <= n; i++){
        Add(t[i], -1);
        S[a[i]]++;
        ans += Query(S[a[i]] - 1);
    }
    cout << ans << endl;
}