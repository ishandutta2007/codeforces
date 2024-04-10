#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

char bd[2100][2100];
int up[2100][2100];
int le[2100][2100];
int dp[2100][2100];
int n,m,k;
int ct[2100], best;


const int initBit = 1024;
int diags[4100][2100];

int findG(int s, int cumFre, bool ooo=false){
    int idx = 0;
    int bitMask = initBit;

    while (bitMask){
        int tIdx = idx + bitMask;
        if (tIdx <= 2010 && cumFre >= diags[s][tIdx]){ 
            idx = tIdx;
            cumFre -= diags[s][tIdx];
        }
        bitMask >>= 1;
    }
    return idx;
}

int count(int s, int a) {
    int c = 0;
    while (a > 0) {
        c += diags[s][a];
        a -= a&-a;
    }
    return c;
}

void ss(int s, int a, int d) {
    while (a <= 2010) {
        diags[s][a] += d;
        a += a&-a;
    }
}

void erase(int s, int a) {
    a++;
    if (count(s,a) != count(s,a-1)) ss(s,a,-1);
}

void insert(int s, int a) {
    a++;
    if (count(s,a) == count(s,a-1)) ss(s,a,1);
}


int vals[4300][2100];
int gloit;

void upd(int x, int y) {
    gloit++;
    int nd = min(le[x][y], up[x][y]);

    int d = x-y+2000;
    int ind = min(x,y);

    //printf("(%d,%d) turns to %d\n", x,y,nd);

    int pr = findG(d, count(d, ind+1)-1);
    int prval = vals[d][pr];
    int nxt = findG(d, count(d,pr+1));
    int nxtval = vals[d][nxt];

    //printf("prev %d %d next %d %d\n", pr, prval, nxt, nxtval);
    
    if (ind - pr + prval <= nd) return;
    vals[d][ind] = nd;
    ct[prval + (nxt-pr)]++;
    ct[prval + (ind-pr)]--;
    
    insert(d,ind);
    ct[nd]++;
    ct[nd + (nxt-ind)]--;

    while (nxtval > nd + nxt-ind) {
        gloit++;
        int nnxt = findG(d, count(d,nxt+1));
        int nnxtval = vals[d][nnxt];
        erase(d,nxt);
        ct[nxtval]--;
        ct[nxtval + (nnxt-nxt)]++;
        ct[nd + (nxt-ind)]++;
        ct[nd + (nnxt-ind)]--;
        nxt = nnxt;
        nxtval = nnxtval;
    }
}

void rem(int x, int y) {
    le[x][y] = up[x][y] = 0;
    upd(x,y);
    for (int ny = y+1; ny < m; ny++) {
        up[x][ny] = min(up[x][ny], up[x][ny-1] + 1);
        upd(x,ny);
    }
    for (int nx = x+1; nx < n; nx++) {
        le[nx][y] = min(le[nx][y], le[nx-1][y] + 1);
        upd(nx,y);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    REP(i,n) scanf("%s", bd[i]);

    REP(edx, n-1) {
        int d = edx - (m-1) + 2000;
        int dlen = min(edx, m-1)+1;
        insert(d,dlen);
    }
    REP(edy, m) {
        int d = (n-1) - edy + 2000;
        int dlen = min(n-1, edy)+1;
        insert(d,dlen);
    }

    REP(i,n) {
        REP(j, m) {
            if (bd[i][j] == 'X') le[i][j] = 0;
            else le[i][j] = 1 + (j==0 ? 0 : le[i][j-1]);
        }
    }

    REP(j,m) {
        REP(i, n) {
            if (bd[i][j] == 'X') up[i][j] = 0;
            else up[i][j] = 1 + (i==0 ? 0 : up[i-1][j]);
        }
    }

    REP(i, n) {
        REP(j, m) {
            int d = i-j+2000;
            int idx = min(i,j);
            vals[d][idx] = min(up[i][j], le[i][j]);
            if (idx) vals[d][idx] = min(vals[d][idx], vals[d][idx-1]+1);
            if (i == 0 || j == 0 || dp[i][j] != dp[i-1][j-1]+1) {
                insert(d,idx);
            }
            ct[vals[d][idx]]++;
            ct[vals[d][idx]+1]--;
        }
    }

    REP(i, k) {
        int x, y;
        scanf("%d %d", &x, &y); x--; y--;
        rem(x,y);
        
        int a = 0;
        int ret = 0;
        REP(i, 2010) {
            a += ct[i];
            if (a > 0) ret = i;
        }

        printf("%d\n", ret);
    }
    fprintf(stderr, "%d\n", gloit);
}