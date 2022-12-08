#include <iostream>
#include <cstdio>

#include <cassert>
#include <bitset>

using namespace std;

const int MAXN = 3e4 + 100;
const int MAXM = 5e4 + 100;
const int MAXW = 12;

int N, M, W;

int c[1 << MAXW][1 << MAXW];
bool u[1 << MAXW][1 << MAXW];       //used for debugging
char s[MAXW + 10];

int v[MAXN], iv[(1 << MAXW)];

int main() {
    scanf("%d%d%d", &W, &N, &M);
    
    for(int i = 0;i < (1 << W);i++) for(int j = 0;j < (1 << W);j++) c[i][j] = 0, u[i][j] = i == j;
    for(int i = 0;i < (1 << W);i++) iv[i] = 0;
    for(int i = 0;i < N;i++) {
        scanf("%d", v + i);
        iv[v[i]]++;
        c[v[i]][v[i]]++;
    }
    for(int j = 1;j < (1 << W);j++) for(int i = 0;i < (1 << W);i++) {
        int l = i xor j;
        for(int k = W - 1;k >= 0;k--) {
            if(j&(1 << k)) {
                assert(u[i xor (1 << k)][l] and u[i][l xor (1 << k)]);
                c[i][l] = c[i xor (1 << k)][l] + c[i][l xor (1 << k)];
                break;
            }
        }
        u[i][l] = true;
    }
    
    for(int i = 0;i < (1 << W);i++) for(int j = 0;j < (1 << W);j++) assert(c[i][j] == c[j][i]);
    
    for(int i = 0;i < M;i++) {
        scanf("%s", s);
        int ans = 0;
        
        int Av = 0;
        int Ov = 0;
        int Xv = 0;
        
        int av = 0;
        int ov = 0;
        int xv = 0;
        
        for(int i = 0;i < W;i++) {
            if(s[W - i - 1] == 'A') Av += (1 << i);
            if(s[W - i - 1] == 'O') Ov += (1 << i);
            if(s[W - i - 1] == 'X') Xv += (1 << i);
            if(s[W - i - 1] == 'a') av += (1 << i);
            if(s[W - i - 1] == 'o') ov += (1 << i);
            if(s[W - i - 1] == 'x') xv += (1 << i);
        }
        
        for(int j = 0;j < (1 << W);j++) {
            if((~j)&av) continue;
            if(j&Ov) continue;
            
            int x1 = ((j|ov) xor xv) & (~Av);
            int x2 = ((j xor ov) xor xv) xor Av;
            
            //cout << bitset<4> (j) << '\n' << bitset<4> (x1) << '\n' << bitset<4> (x2) << '\n' << iv[j] << ' ' << c[x1][x2] << "\n\n";
            
            ans += iv[j] * c[x1][x2];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}