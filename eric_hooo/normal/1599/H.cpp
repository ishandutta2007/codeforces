#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int X0=2,Y0=3,X1=4,Y1=5;

long long query(long long x, long long y) {
    #ifdef DEBUG
    {
        long long ans=1LL<<60;
        for(int a=X0;a<=X1;++a)for(int b=Y0;b<=Y1;++b)
            ans=std::min(ans,std::abs(x-a)+std::abs(y-b));
        return ans;
    }
    #endif
    printf("? %lld %lld\n", x, y);
    fflush(stdout);
    long long d;
    scanf("%lld", &d);
    return d;
}

const long long N = 1e9;

int main() {
    long long A1 = query(1, 1);
    long long A2 = query(1, N);
    long long A3 = query(N, 1);
    long long A4 = query(N, N);
    long long x = std::min(N, 1 + (A1 - 1));
    long long lb = 1, rb = x;
    while (lb < rb) {
        long long md = (lb + rb + 1) >> 1;
        if (query(md, 1) == A1 - (md - 1)) lb = md;
        else rb = md - 1;
    }
    long long x0 = lb, y0 = A1 + 2 - x0;
    long long y1 = -(A2 + 1 - N - x0), x1 = -(A4 - 2 * N + y1);
    printf("! %lld %lld %lld %lld\n", x0, y0, x1, y1);
    fflush(stdout);
    return 0;
}