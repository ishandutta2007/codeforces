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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int ans[N], a[N], n, p;
char str[N];
int Get(int i){
    if (i == 1){
        if (a[i] == p) return -1;
        return a[i] + 1;
    }
    int x = a[i] + 1;
    while (x <= p){
        if (x != a[i - 1] && x != a[i - 2]) return x;
        x++;
    }
    return -1;
}
bool Gao(int a, int b, int x){
    if (x > n) return 1;
    if (a != 1 && b != 1){
        ans[x] = 1;
        return Gao(b, 1, x + 1);
    }else if (a + b == 3){
        if (p < 3) return 0;
        ans[x] = 3;
        return Gao(b, 3, x + 1);
    }else if (a == 1 || b == 1){
        if (p < 2) return 0;
        ans[x] = 2;
        return Gao(b, 2, x + 1);
    }
    return 0;
}
int main(){
    scanf("%d%d", &n, &p);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) a[i] = str[i] - 'a' + 1;
    for (int i = n; i >= 1; i--)
    if (a[i] < p){
        int t = Get(i);
        if (t == -1) continue;
        if (Gao(a[i - 1], t, i + 1)){
            for (int j = 1; j < i; j++) printf("%c", a[j] + 'a' - 1); printf("%c", t + 'a' - 1);
            for (int j = i + 1; j <= n; j++) printf("%c", ans[j] + 'a' - 1); puts("");
            return 0;
        }
    }
    puts("NO");
}