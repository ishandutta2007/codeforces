#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

typedef long long ll;
int N, M;

#define INF 1000000000
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define itr iterator
#define sz size()

double pd[211][210][210];
int n,l,k;

struct tour {
    int prob, bag;
    bool operator<(const tour& ot) const {
        return bag < ot.bag;
    }
} t[210];
 
int main() {
    scanf("%d %d %d", &n, &l, &k);
    REP(i, n) {
        scanf("%d", &t[i+1].prob);
    }
    REP(i, n) scanf("%d", &t[i+1].bag);
    
    sort(t+1, t+n+1);
    
    for (int p = 0; p <= 200; p++) pd[0][0][p] = 1;
    for (int need_win = 1; need_win <= 200; need_win++) {
        for (int p = 0; p <= 200; p++) pd[0][need_win][p] = 0;
    }
    
    for (int g = 1; g <= n; g++) {
        for (int nw = 0; nw <= 200; nw++) {
            for (int p = 0; p <= 200; p++) {
                pd[g][nw][p] = 0;
                if (t[g].bag == -1 && p == 0);
                else {
                    int nb = p+t[g].bag;
                    if (nb > 200) nb = 200;
                    
                    int nnw = nw-1;
                    if (nnw < 0) nnw = 0;
                    pd[g][nw][p] += t[g].prob * pd[g-1][nnw][nb] / 100;
                }
                
                pd[g][nw][p] += (100-t[g].prob) * pd[g-1][nw][p] / 100;
            }
        }
    }
    
    printf("%lf\n", pd[n][l][k]);
}