#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 320000
long long Left[MAXN], Right[MAXN], ans;
char s[MAXN];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i += 1){
        scanf("%s", s);
        int m = strlen(s);
        int l = 0, r = 0;
        for(int j = 0; j < m; j += 1){
            if(s[j] == '(') l += 1;
            else l -= 1;
            if(l < 0) break;
        }
        if(l >= 0) Left[l] += 1;
        for(int j = m - 1; j >= 0; j -= 1){
            if(s[j] == ')') r += 1;
            else r -= 1;
            if(r < 0) break;
        }
        if(r >= 0) Right[r] += 1;
    }
    for(int i = 0; i < MAXN; i += 1) ans += Left[i] * Right[i];
    printf("%lld", ans);
}