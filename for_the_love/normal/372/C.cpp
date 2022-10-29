#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 155555;
const int M = 333;


int q[N], n, m;
long long d, f[2][N], a[M], b[M], t[M];

int main(){
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> t[i];
    for (int i = 1; i <= n; i++) f[m & 1][i] = b[m] - abs(a[m] - i);

    for (int i = m - 1; i >= 1; i--){
        int head = 1, tail = 0;
        for (int j = 1; j <= n; j++){
            while (head <= tail && (t[i + 1] - t[i]) * d < j - q[head]) head++;
            while (head <= tail && f[i & 1 ^ 1][j] >= f[i & 1 ^ 1][q[tail]]) tail--;
            q[++tail] = j;
            f[i & 1][j] = f[i & 1 ^ 1][q[head]] + (b[i] - abs(a[i] - j));
        }
        head = 1, tail = 0;
        for (int j = n; j >= 1; j--){
            while (head <= tail && (t[i + 1] - t[i]) * d < q[head] - j) head++;
            while (head <= tail && f[i & 1 ^ 1][j] >= f[i & 1 ^ 1][q[tail]]) tail--;
            q[++tail] = j;
            f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][q[head]] + (b[i] - abs(a[i] - j)));
        }
    }
    long long ans = -1e18;
    for (int i = 1; i <= n; i++) ans = max(ans, f[1][i]);
    cout << ans << endl;
}