#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 100;
int N, a[MAXN];
int s[MAXN], ss;
int ps[MAXN];

int ct[MAXN];
int gct(int n) {
    if(n > N) return 0;
    return ct[n];
}

typedef long long ll;

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", a + i);
    sort(a, a + N);
    
    ss = 0;
    for(int i = 0, j;i < N;i = j) {
        for(j = i + 1;j < N and a[i] == a[j];j++);
        s[ss++] = j - i;
    }
    sort(s, s + ss);
    
    for(int i = 0;i <= N;i++) ps[i] = 0;
    ps[N + 1] = 0;
    for(int i = N, j = ss - 1;i >= 0;i--) {
        ps[i] = ps[i+1];
        for(;j >= 0 and s[j] == i;j--) ps[i]++;
    }
    
    ll ans = 0, t;
    for(int i = N;i >= 1;i--) {
        int p = gct(i*2);
        if(ps[i] >= p + 1) ct[i] = p + 1; else ct[i] = p;
        
        if((t = i*((1 << ct[i]) - 1)) > ans) ans = t;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}