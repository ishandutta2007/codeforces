#include<bits/stdc++.h>

using namespace std;

int G[5][5];

#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
for(int i = 0; i < 5; i++) 
for(int j = 0; j < 5; j++) 
cin >> G[i][j];
int res = 0;
REP(a, 5) 
REP(b, 5) 
REP(c, 5)
REP(d, 5)
REP(e, 5)
if(a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e) {
int v = G[a][b] + G[b][a] + G[b][c] + G[c][b] + 2 * (G[c][d] + G[d][c]) + 2 * (G[d][e] + G[e][d]);
if(v > res) res = v;
}
cout << res << '\n';
}