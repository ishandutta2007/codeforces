#include <iostream>
#include <cstdio>

using namespace std;

int N;
typedef long long ll;

const int MAXC = 1e9 - 1;

char in[20];

bool get_res(ll x, ll y, bool rev = false) {
    if(!rev) printf("%lld %lld\n", x, y); else printf("%lld %lld\n", y, x);
    fflush(stdout);
    scanf(" %s", in);
    return in[0] == 'b';
}

int main() {
    scanf("%d", &N);
    
    if(N == 1) {
        get_res(1, 1);
        printf("2 2 2 3\n");
        return 0;
    }
    
    bool tr = get_res(MAXC, MAXC);
    bool br = get_res(MAXC, 0);
    
    bool rev = !(tr xor br);
    int l = 1, h = MAXC;
    for(int i = 0;i < N - 2;i++) {
        int m = l + ((h - l)>>1);
        if(tr == get_res(MAXC, m, rev)) h = m;
        else l = m;
    }
    
    if(!rev) printf("0 0 %d %d\n", MAXC + 1, h); else printf("0 0 %d %d\n", h, MAXC + 1);
    
    return 0;
}