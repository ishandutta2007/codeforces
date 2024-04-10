#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

int N;

int l[MAXN];

int e[MAXN][2], ec;
int nu[MAXN], nub, nus;

int main() {
    scanf("%d", &N);
    
    bool ans = true;
    
    l[0] = 0;
    for(int i = 0;i < N - 1;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        
        if(a != N and b != N) ans = false;
        
        if(a == N) l[i] = b;
        else l[i] = a;
    }
    
    sort(l, l + N - 1);
    
    ec = nus = nub = 0;
    
    for(int i = 1, j = 0;ans and i < N;i++) {
        int p = N;
        if(l[j] != i) {
            nu[nus++] = i;
            continue;
        }
        j++;
        while(j < N - 1 and l[j] <= i) {
            if(nub >= nus) {
                ans = false;
                break;
            }
            e[ec][0] = p;
            e[ec][1] = p = nu[nub++];
            ec++;
            j++;
        }
        e[ec][0] = p;
        e[ec][1] = i;
        ec++;
    }
    
    if(ans) {
        printf("YES\n");
        for(int i = 0;i < ec;i++) printf("%d %d\n", e[i][0], e[i][1]);
    } else printf("NO\n");
    
    return 0;
}