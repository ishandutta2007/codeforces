#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


vector<int> gen(int n) {
    if (n == 1) return {1};
    if (n == 2) return {3, 4};

    vector<int> ret(n, 1);
    int diff = n-1;
    if (diff % 2 == 0) {
        ret[n-2] = 2;
        diff += 3;
    }
    ret[n-1] = diff/2;

    return ret;
}

void solve() {
    int n,m;
    scanf("%d %d", &n, &m);

    vector<int> row = gen(n);
    vector<int> col = gen(m);

    REP(i,n) {
        REP(j,m) {
            printf("%d ", row[i] * col[j]);
        }
        printf("\n");
    }
}


int main() {
    solve();
}