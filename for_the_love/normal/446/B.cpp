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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

priority_queue <LL> C, R;

LL c[N], r[N], A[N], B[N];
int main(){
    int n, m, k, p, x;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        scanf("%d", &x);
        r[i] += x;
        c[j] += x;
    }
    for (int i = 0; i < n; i++) R.push(r[i]);
    for (int i = 0; i < m; i++) C.push(c[i]);
    LL sum = 0;
    for (int i = 1; i <= k; i++){
        LL x = R.top(); R.pop();
        sum += x; R.push(x - m * p);
        A[i] = sum;
    }
    sum = 0;
    for (int i = 1; i <= k; i++){
        LL x = C.top(); C.pop();
        sum += x; C.push(x - n * p);
        B[i] = sum;
    }
    LL ans = -1e18;
    for (int i = 0; i <= k; i++) ans = max(ans, A[i] + B[k - i] - (LL)i * p * (k - i));
    for (int i = 0; i <= k; i++) ans = max(ans, B[i] + A[k - i] - (LL)i * p * (k - i));
    cout << ans << endl;
}