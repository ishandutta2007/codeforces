#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define N 101000  
int s[N], a[N], n, m, x, y, z;  
bool f[N];  
  
void init() {  
    int x;  
    bool flag;  
    for (int i=0; i<10004; i++) {  
        flag = true;  
        x = i;  
        while (x) {  
            if (x%10!=4 && x%10!=7) {  
                flag = false; break;  
            }  
            x /= 10;  
        }  
        if (flag) f[i] = true;  
        else f[i] = false;  
    }  
    memset(s, 0, sizeof(s));  
}  
inline int lowbit(int x) { return x&(-x); }  
void add(int x, int v) {  
    while (x <= n) {  
        s[x] += v;  
        x += lowbit(x);  
    }  
}  
int sum(int x) {  
    int ret = 0;  
    while (x) {  
        ret += s[x];  
        x -= lowbit(x);  
    }  
    return ret;  
}  
int main() {  
    init();  
    scanf("%d%d", &n, &m);  
    for (int i=1; i<=n; i++) {  
        scanf("%d", &a[i]);  
        if (f[a[i]]) add(i, 1);  
    }  
  
    char op[10];  
    while (m--) {  
        scanf(" %s %d %d", op, &x, &y);  
        if (op[0] == 'c') printf("%d\n", sum(y)-sum(x-1));  
        else {  
            scanf("%d", &z);  
            if (z == 0) continue;  
            for (int i=x; i<=y; i++) {  
                if (f[a[i]]) add(i, -1);  
                a[i] += z;  
                if (f[a[i]]) add(i, 1);  
            }  
        }  
    }  
  
    return 0;  
}