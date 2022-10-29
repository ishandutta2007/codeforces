#include <bits/stdc++.h>
#define N 200002
using namespace std;
int n, c[N];
char s[N];
bool vis[N];
int main() {
    scanf("%d%s", &n, s);
    for(int i = 1; i <= n; ++ i) if(n % i == 0) c[i] = n / i;
    for(int i = n; i; -- i) if(n % i == 0)
        for(int j = i + i; j <= n; j += i) c[i] -= c[j];
    int ans = 0;
    for(int i = 1; i <= n; ++ i) if(n % i == 0) {
        bool flag = 1;
        for(int j = 0; j < n; ++ j) vis[j] = 0;
        for(int j = 0; j < n; ++ j) if(!vis[j]) {
            int x = j, y = 0;
            while(!vis[x]) y ^= s[x] - '0', vis[x] = 1, x = (x + i) % n;
            if(y) { flag = 0; break; }
        }
        if(flag) ans += c[i];
    }
    printf("%d\n", ans);
}