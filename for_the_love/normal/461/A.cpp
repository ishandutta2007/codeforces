#include <map>
#include <set>
#include <cmath>
#include <queue>
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
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int a[N];

int main(){
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    LL ans = sum;
    for (int i = 1; i < n; i++){
        ans += sum;
        sum -= a[i];
    }
    cout << ans << endl;
}