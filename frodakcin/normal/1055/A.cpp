#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 100;

int N, S;
int A[MAXN], B[MAXN];

void ans(bool b) {
    if(b) printf("YES\n"); else printf("NO\n");
    exit(0);
}

int main() {
    scanf("%d%d", &N, &S);
    for(int i = 1;i <= N;i++) scanf("%d", A + i);
    for(int i = 1;i <= N;i++) scanf("%d", B + i);
    
    int c = 1;
    bool d = true;
    
    if(A[1] == 0) ans(false);
    if(A[S] == 1) ans(true);
    if(B[S] == 0) ans(false);
    for(int i = S + 1;i <= N;i++) if(A[i] == 1 and B[i] == 1) ans(true);
    ans(false);
    
    return 0;
}