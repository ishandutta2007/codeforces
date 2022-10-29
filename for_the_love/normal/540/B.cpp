#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const int eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int a[N];

int main(){
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    int m = (n + 1) / 2;
    for (int i = 0; i < k; i++) scanf("%d", &a[i]);
    for (int i = y; i <= p; i++){
        int flag = 0, sum = 0, cnt = 0, cnt2 = 0;
        for (int j = 0; j < k; j++){
            sum += a[j];
            if (a[j] == i) flag = 1, cnt2++;
            if (a[j] < i) cnt++;
        }
        if (cnt >= m) continue;
        int l = n - k;
        if (!flag) l--, sum += i, cnt2++;
        if (m - cnt2 - cnt > l) continue;
        int t = min(m - 1 - cnt, l);
        l -= t;
        sum += t;
        sum += l * i;
        if (sum <= x){
            //printf("%d\n", sum);
            for (int j = 0; j < l + (1 - flag); j++) printf("%d ", i);
            for (int j = 0; j < t; j++) printf("%d ", 1);
            puts("");
            return 0;
        }
    }
    puts("-1");
}