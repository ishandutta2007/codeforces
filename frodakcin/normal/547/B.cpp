#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2e5 + 1000;

int N;
int a[MAXN], ans[MAXN], L[MAXN], R[MAXN];
int st[MAXN], sts;

int rpl(int& a, const int& b) {
    if(a < b) a = b;
    return a;
}

int main() {
    scanf("%d", &N);
    for(int i = 1;i <= N;i++) scanf("%d", a + i);
    a[0] = a[N + 1] = -1;
    
    sts = 0;
    st[sts++] = 0;
    for(int i = 1;i <= N;i++) {
        while(sts > 0 and a[i] <= a[st[sts-1]]) sts--;
        L[i] = st[sts-1];
        st[sts++] = i;
    }
    
    sts = 0;
    st[sts++] = N + 1;
    for(int i = N;i >= 1;i--) {
        while(sts > 0 and a[i] <= a[st[sts-1]]) sts--;
        R[i] = st[sts-1];
        st[sts++] = i;
    }
    
    for(int i = 0;i <= N + 1;i++) ans[i] = 0;
    for(int i = 1;i <= N;i++) {
        int d = R[i] - L[i] - 1;
        rpl(ans[d], a[i]);
    }
    
    for(int i = N;i >= 1;i--) rpl(ans[i], ans[i+1]);
    for(int i = 1;i <= N;i++) printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}