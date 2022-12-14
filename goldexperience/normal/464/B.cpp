#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int d[6][3] = {0, 1, 2,
                     0, 2, 1,
                     1, 0, 2,
                     1, 2, 0,
                     2, 0, 1,
                     2, 1, 0};

LL dd[100];
int c[10][3], origin[10][3];

LL sqr(int t){
    return (LL)t * t;
}

LL dist(int a[], int b[]){
    return sqr(a[0] - b[0]) + sqr(a[1] - b[1]) + sqr(a[2] - b[2]);
}

bool dfs(int u){
    if (u == 8){
        int tot = 0;
        LL D;
        for (int i = 0; i < 8; ++i)
            for (int j = i + 1; j < 8; ++j){
                dd[tot++] = dist(c[i], c[j]);
                if (tot == 1){
                    D = dd[0]; 
                }else if (dd[tot - 1] < D){
                    D = dd[tot - 1];
                } 
                if (D == 0) return false;
            }
        int s1 = 0, s2 = 0, s3 = 0;
        for (int i = 0; i < tot; ++i)
            if (dd[i] == D) ++s1; else 
                if (dd[i] == D + D) ++s2; else
                    if (dd[i] == D + D + D) ++s3; else return false;
        if (s1 != 12 || s2 != 12 || s3 != 4) return false;
        return true;
    }
    for (int i = 0; i < 6; ++i){
        c[u][0] = origin[u][d[i][0]];
        c[u][1] = origin[u][d[i][1]];
        c[u][2] = origin[u][d[i][2]];
        if (dfs(u + 1)) return true;
    }
    return false;
}

int main(){
    for (int i = 0; i < 8; ++i){
        scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
        origin[i][0] = c[i][0];
        origin[i][1] = c[i][1];
        origin[i][2] = c[i][2];
    }
    if (dfs(1)){
        puts("YES");
        for (int i = 0; i < 8; ++i)
            printf("%d %d %d\n", c[i][0], c[i][1], c[i][2]);
    } else puts("NO");
    return 0;
}