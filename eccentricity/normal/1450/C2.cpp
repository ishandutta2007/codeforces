#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 302;
int x[maxn], y[maxn];
char s[maxn][maxn];
int cntX[maxn], cntO[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> s[i];
        for(int k = 0; k < 3; k += 1) cntX[k] = cntO[k] = 0;
        int m = 0;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1){
                if(s[i][j] == 'X')
                    cntX[(i + j) % 3] += 1;
                if(s[i][j] == 'O')
                    cntO[(i + j) % 3] += 1;
                m += s[i][j] != '.';
            }
        int f = 1;
        for(int x = 0; x < 3 and f; x += 1)
            for(int y = 0; y < 3 and f; y += 1)
                if(x != y) if((cntO[x] + cntX[y]) * 3 <= m){
                    for(int i = 0; i < n; i += 1)
                        for(int j = 0; j < n; j += 1){
                            if(s[i][j] != '.'){
                                if((i + j) % 3 == x) s[i][j] = 'X';
                                if((i + j) % 3 == y) s[i][j] = 'O';
                            }
                        }
                    for(int i = 0; i < n; i += 1) cout << s[i] << "\n";
                    f = 0;
                }
        assert(f == 0);
    }
    return 0;
}