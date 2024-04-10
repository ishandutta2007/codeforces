#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
const int N = 2e7 + 1;
int f[N];
int sqr(int x){
    return x * x;
}
int main() {
    int T = 1;
   // scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int nn = n;
        while (n --) {
            int v = 0;
            for (int i = 0; i < 3; i ++){
                char c;
                scanf(" %c", &c);
                v |= (1 << (int(c -'a')));
            }
            f[v] ++;
        }
        for (int i = 0; i < 24; i ++) {
            for (int j = 0; j < (1 << 24) ; j ++)
                if (j & (1 << i))
                    f[j] += f[j ^ (1 << i)];
        }
        int ans = 0;
        for (int i = 0; i < (1 << 24) ;  i++)
            ans ^= sqr(nn - f[(1 << 24) - 1 - i]);
        printf("%d\n",ans);
    }
    return 0;
}