#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXM = 10;

typedef long long ll;

int N, M;
int p[MAXM][MAXN];
int f[MAXM][MAXN];

int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i < M;i++) for(int j = 0;j < N;j++) scanf("%d", p[i] + j);
    for(int i = 0;i < M;i++) for(int j = 0;j < N;j++) f[i][p[i][j]] = j;
    
    ll ans = 0;
    int c = 0;
    for(int i = 0;i < N;i++) {
        int ch = p[0][i];
        while(true) {
            if(i + c >= N) break;
            bool w = true;
            for(int m = 1;m < M;m++) {
                if(f[m][ch] + c >= N or p[m][f[m][ch] + c] != p[0][i + c]) {w = false; break;}
            }
            if(!w) break;
            c++;
        }
        ans += c--;
    }
    
    printf("%lld\n", ans);
}