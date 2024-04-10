#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 1010000;
const int INF = 101000000;

int N;
int xv[MAXN * 2], xvl;
int rm[MAXN * 2][2];        //rightmost [0] node of set, 2nd rightmost [1] of set
int exams[MAXN][2], perday[MAXN * 2];

//DISJOINT UNION
int dsup[MAXN * 2], dsus[MAXN * 2], exnum[MAXN * 2];     //parent, size (AKA columns occupied), number of exams
void dsui(int n) {
    for(int i = 0;i <= n;i++) {
        dsup[i] = i;
        dsus[i] = 1;
        exnum[i] = 1;
        rm[i][0] = i;
        rm[i][1] = -1;
    }
}
int dsuf(int n) {
    if(dsup[n] == n) return n;
    return (dsup[n] = dsuf(dsup[n]));
}
void dsum(int a, int b) {
    a = dsuf(a);
    b = dsuf(b);
    if(a == b) return;
    if(dsus[b] > dsus[a]) swap(a, b);
    dsup[b] = a;
    dsus[a] += dsus[b], dsus[b] = 0;
    for(int i = 0;i < 2;i++) {
        int t = rm[b][i];
        for(int j = 0;j < 2;j++) 
            if(t > rm[a][j]) 
                swap(t, rm[a][j]);
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) {
        scanf("%d%d", &exams[i][0], &exams[i][1]);
        xv[i * 2] = exams[i][0];
        xv[i * 2 + 1] = exams[i][1];
    }
    sort(xv, xv + 2 * N);
    xvl = unique(xv, xv + 2 * N) - xv;
    dsui(xvl);
    
    for(int i = 0;i < xvl;i++) {
        perday[i] = 0;
    }
    
    for(int i = 0;i < N;i++) {
        for (int j = 0;j < 2;j++) perday[ (exams[i][j] = (lower_bound(xv, xv + xvl, exams[i][j]) - xv)) ]++;
        dsum(exams[i][0], exams[i][1]);
    }
    for(int i = 0;i < xvl;i++) {
        exnum[dsuf(i)] += perday[i];
    }
    int ans = -1;
    for(int i = 0;i < xvl;i++) {
        int l = dsuf(i);
        int t = dsus[l] - exnum[l]/2;
        if(t < 0) {ans = -1; break;}
        assert(t <= 2);
        if(rm[l][t] > ans) ans = rm[l][t];
    }
    printf("%d\n", (ans == -1 ? -1 : xv[ans]));
    return 0;
}