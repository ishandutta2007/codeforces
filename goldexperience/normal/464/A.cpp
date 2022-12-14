#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 111111;

int n, p;
int ans[maxn], c[maxn];
char buf[maxn];

int main(){
    scanf("%d%d", &n, &p);
    scanf("%s", buf + 1);
    for (int i = 1; i <= n; ++i) c[i] = buf[i] - 'a' + 1;
    bool flag = false;
    for (int i = n; i >= 1; --i){
        ans[i] = c[i] + 1;
        if (i == 1 && ans[i] > p) break;
        while ((i > 1 && ans[i] == c[i - 1]) || (i > 2 && c[i - 2] == ans[i])) ++ans[i];
        if (ans[i] > p) continue;

        flag = true;
        for (int j = 1; j < i; ++j) ans[j] = c[j];
        for (int j = i + 1; j <= n; ++j)
            for (int k = 1; k <= p; ++k)
                if (k != ans[j - 1] && (j <= 2 || k != ans[j - 2])){
                    ans[j] = k;
                    break;
                }
        break;
    }
    if (flag){
        for (int i = 1; i <= n; ++i)
            putchar((char)('a' + ans[i] - 1));
        puts("");
    } else puts("NO");
    return 0;
}