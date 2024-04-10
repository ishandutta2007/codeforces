#include<bits/stdc++.h>
using namespace std;
using LD = long double;
constexpr int maxn = 120;
int h[maxn][maxn], a[maxn][maxn];
int t[maxn];
LD E[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 1; i <= 10; i += 1)
        for(int j = 1; j <= 10; j += 1) cin >> h[i][j];
    for(int i = 1; i <= 10; i += 1)
        for(int j = 1; j <= 10; j += 1)
            if(i & 1) a[i][j] = (i - 1) * 10 + j;
            else a[i][j] = (i - 1) * 10 + 11 - j;
    for(int i = 1; i <= 10; i += 1)
        for(int j = 1; j <= 10; j += 1)
            if(h[i][j]) t[a[i][j]] = a[i - h[i][j]][j];
            else t[a[i][j]] = a[i][j];
    for(int i = 2; i <= 100; i += 1)
        if(i <= 6) E[i] = 6;
        else{
            E[i] = 1;
            for(int j = 1; j <= 6; j += 1) E[i] += min(E[i - j], E[t[i - j]]) / 6;
        }
    cout << setprecision(20) << E[100];
    return 0;
}