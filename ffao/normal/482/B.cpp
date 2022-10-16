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

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n,m;
int prh[110000][30];
int c[30];
int p[30];
int res[110000];
int gd[110000][40];

pair< pair<int, int>, int> qs[110000];
int maxp, maxj;
int l,r,q;

int gcd(int a, int b) {return a&b;}

int get_min(int a, int b){
    if (a > b) swap(a,b);
    
    int res = gd[a][0];
    int nxt = a+1;
    for (int p=maxp, j=maxj; j >= 0; j--, p>>=1) {
        if (nxt + p > b+1) continue;
        res = gcd(res, gd[nxt][j]);
        nxt += p;
    }

    return res;
}

int main() {
    scanf("%d %d", &n, &m);

    p[0] = 1;
    for (int i = 1; i < 30; i++) p[i] = 2*p[i-1];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &l ,&r, &q);
        l--; r--;
        qs[i] = make_pair( make_pair(l,r), q);
        
        for (int b = 0; b < 30; b++) {
            if (q & 1) {
                prh[l][b]++;
                prh[r+1][b]--;
            }

            q >>= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int b = 0; b < 30; b++) {
            c[b] += prh[i][b];
            if (c[b]) res[i] += p[b];
        }
    }

    maxp = 1;
    maxj = 0;
    while (maxp*2 < n) {
        maxp <<= 1;
        maxj++;
    }

    for (int i = 0; i < n; i++) gd[i][0] = res[i];

    for (int p = 1, j = 1; p <= n; p <<= 1, j++) {
        for (int i = 0; i < n; i++) {
            gd[i][j] = gcd(gd[i][j-1], gd[i+p][j-1]);
        }
    }

    bool ok= true;
    for (int i = 0; i < m; i++) {
        if (get_min(qs[i].first.first, qs[i].first.second) != qs[i].second) ok = false;
    }

    if (!ok) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < n; i++) printf("%d ", res[i]);
    }
}