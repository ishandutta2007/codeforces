#include <bits/stdc++.h>
#define rep(i,n)   for(int i = 0; i < int(n); i++)
using namespace std;

int v[303][303];
double s[303];

const int D = 2500;

inline int fastMax(int x, int y) { return x>y?x:y; }

int main(){
    int n,k;
    cin >> n >> k;
    rep(i,n) rep(j,k+1) cin >> v[i][j];

    rep(x,k) rep(d,D+1){
        int h, ymax = 0;
        rep(i,n){
            int ycur = v[i][x] * (D-d) + v[i][x+1] * d;
            h = fastMax(0,ycur-ymax);
            ymax = fastMax(ymax, ycur);
            s[i] += h;
            if(d != 0 && d != D) s[i] += h;
        }
    }

    rep(i,n) printf("%.9f\n",s[i]/D/5000);
}