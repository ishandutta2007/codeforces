#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 2e5 + 1000;

int N;
char s[MAXN];

void ans(int sk) {
    for(int i = 0;i < N;i++) if(i != sk) printf("%c", s[i]);
    printf("\n");
    exit(0);
}

int main() {
    scanf("%d", &N);
    scanf(" %s", s);
    
    for(int i = 0;i < N;i++) {
        if(i == N - 1) ans(N-1);
        
        if(s[i + 1] < s[i]) ans(i);
    }
    
    assert(false);
    
    return 0;
}