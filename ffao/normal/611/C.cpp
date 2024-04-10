#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


char board[1100][1100];
int h,w;
int ri[1100][1100];
int dn[1100][1100];

void solve()
{
    re(h,w);
    for (int i = 0; i < h; i++) scanf("%s", board[i]);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j++) {
            ri[i][j] = (board[i][j] == '.' && board[i][j+1] == '.');
            if (j != 0) ri[i][j] += ri[i][j-1];
        }
    }

    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h-1; i++) {
            dn[i][j] = (board[i][j]=='.' && board[i+1][j] == '.');
            if (i != 0) dn[i][j] += dn[i-1][j];
        }
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int i1,i2,j1,j2;
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2); i1--; i2--; j1--; j2--;

        int ans = 0;
        for (int c = j1; c <= j2; c++) {
            if (i2 != 0) ans += dn[i2-1][c];
            if (i1 != 0) ans -= dn[i1-1][c];
        }

        for (int r = i1; r <= i2; r++) {
            if (j2 != 0) ans += ri[r][j2-1];
            if (j1 != 0) ans -= ri[r][j1-1];
        }

        printf("%d\n", ans);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}