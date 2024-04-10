#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll t, n, k, ans, a[MN], f[26];
char s[MN]; string str;

int main() {
    scanf("%lld %lld %s", &n, &k, s); str = s;
    for(char c = 'a'; c <= 'z'; c++)
        for(int i = 0; i < n; i++)
            if(s[i] == c && k) {
                k--;
                a[i] = 1;
            }
    for(int i = 0; i < n; i++) if(!a[i]) printf("%c", s[i]);
    return 0;
}