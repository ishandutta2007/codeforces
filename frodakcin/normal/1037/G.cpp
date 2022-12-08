#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 101000;
const int MAXM = 101000;

const int CH = 26;

int N, M, s[MAXN];
char sraw[MAXN];

int L[MAXN][CH], R[MAXN][CH];
int pfx[MAXN][CH], sfx[MAXN][CH], psm[MAXN];

void initLR() {
    for(int i = 0;i < CH;i++) L[0][i] = 0, L[N][i] = N;
    for(int i = 1;i < N;i++) {
        for(int j = 0;j < CH;j++) L[i][j] = L[i - 1][j];
        L[i][s[i]] = i;
    }
    
    for(int i = 0;i < CH;i++) R[N][i] = N, R[0][i] = 0;
    for(int i = N - 1;i > 0;i--) {
        for(int j = 0;j < CH;j++) R[i][j] = R[i + 1][j];
        R[i][s[i]] = i;
    }
}

void initPFX() {
    int o[CH], t;
    bool u[CH + 1];
    psm[0] = 0;
    
    for(int i = 0;i < CH;i++) pfx[0][i] = 0;
    for(int i = 1;i < N;i++) {
        psm[i] = psm[L[i - 1][s[i]]] xor pfx[i - 1][s[i]];
        
        for(int j = 0;j < CH;j++) o[j] = j;
        
        sort(o, o + CH, [&](const int& a, const int & b){return L[i][a] > L[i][b];});
        
        for(int j = 0;j < CH;j++) {
            for(int k = 0;k <= CH;k++) u[k] = false;
            for(int k = 0;k < j;k++) {
                if(L[i][o[k]] == 0) continue;
                assert(L[i][o[j]] < L[i][o[k]]);
                if((t = pfx[R[L[i - 1][o[j]]][o[k]] - 1][o[j]] xor psm[L[i][o[k]]] xor psm[R[L[i - 1][o[j]] + 1][o[k]]] xor pfx[i][o[k]]) < CH) u[t] = true;
            }
            
            int ans = 0;
            while(u[ans]) ans++;
            pfx[i][o[j]] = ans;
        }
    }
}

void initSFX() {
    int o[CH], t;
    bool u[CH + 1];
    
    for(int i = 0;i < CH;i++) sfx[N][i] = 0;
    for(int i = N - 1;i > 0;i--) {
        for(int j = 0;j < CH;j++) o[j] = j;
        
        sort(o, o + CH, [&](const int& a, const int& b){return R[i][a] < R[i][b];});
        
        for(int j = 0;j < CH;j++) {
            for(int k = 0;k <= CH;k++) u[k] = false;
            for(int k = 0;k < j;k++) {
                if(R[i][o[k]] == N) continue;
                assert(R[i][o[k]] < R[i][o[j]]);
                if((t = sfx[i][o[k]] xor psm[L[R[i + 1][o[j]] - 1][o[k]]] xor psm[R[i][o[k]]] xor sfx[L[R[i + 1][o[j]]][o[k]] + 1][o[j]]) < CH) u[t] = true;
            }
            
            int ans = 0;
            while(u[ans]) ans++;
            sfx[i][o[j]] = ans;
        }
    }
}

int main() {
    scanf(" %s", sraw);
    
    s[0] = -1;
    for(N = 1;sraw[N - 1] != '\0';N++) {
        assert(N < MAXN - 10);
        s[N] = static_cast<int> (sraw[N - 1]) - 97;
    }
    s[N] = -1;
    
    initLR();
    initPFX();
    initSFX();
    
    /*
    for(int i = 1;i < N;i++) {
        printf("%d %d\n", i, sfx[i][1]);
    }
    */
    
    scanf("%d", &M);
    
    int t;
    for(int i = 0;i < M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        assert(1 <= a and a <= b and b < N);
        
        bool u = false;
        for(int c = 0;c < CH;c++) {
            if(R[a][c] > b) continue;
            t = sfx[a][c] xor psm[L[b][c]] xor psm[R[a][c]] xor pfx[b][c];
            if(!t) u = true;
        }
        if(u) printf("Alice\n");
        else printf("Bob\n");
    }
    
    return 0;
}