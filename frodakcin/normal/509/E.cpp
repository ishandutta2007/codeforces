#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

char v[] = "AEIOUY";

bool isvow(const char& c) {
    for(int i = 0;i < 6;i++) if(c == v[i]) return true;
    return false;
}

typedef double ld;
#define tld(x) static_cast<ld>(x) 
typedef long long ll;
#define tll(x) static_cast<ll>(x)

const int MAXN = 5e5 + 100;
int N;
char os[MAXN];
bool s[MAXN];
int psm[MAXN];
ll psm2[MAXN];

int main() {
    scanf("%s", os);
    for(N = 0;os[N] != '\0';N++) s[N + 1] = isvow(os[N]);
    
    psm[0] = psm2[0] = 0;
    for(int i = 1;i <= N;i++) psm2[i] = psm2[i-1] + tll(psm[i] = psm[i-1] + s[i]);
    
    ld ans = 0;
    for(int l = 1;l <= N;l++) {
        ans += tld(psm2[N] - psm2[l-1] - (psm2[N-l] - psm[0]))/tld(l);
    }
    printf("%.7g\n", ans);
    
    return 0;
}