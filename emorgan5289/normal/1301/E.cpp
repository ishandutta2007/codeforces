#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

#define min3(x, y, z) min(x, min(y, z))
#define min4(x, y, z, w) min(min(x, y), min(z, w));

int n, m, q;

int R[505][505], G[505][505], B[505][505], Y[505][505], s[505][505];
int c[505][505];
int table[10][1005][10][1005];

int query(int x1, int y1, int x2, int y2) {
    debug(x1, y1, x2, y2);
    int lenx=x2-x1+1;
    int kx=log2(lenx);
    int leny=y2-y1+1;
    int ky=log2(leny);
    int min_R1 = max ( table[kx ][x1 ][ky ][y1 ] , table[kx ][x1 ][ky ][ y2+1-(1<<ky) ] ) ;
    int min_R2 = max ( table[kx ][x2+1-(1<<kx) ][ky ][y1 ], table[kx ][x2+1-(1<<kx) ][ky ][y2+1-(1<<ky) ] );
    return max ( min_R1, min_R2 );
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    fin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x; fin >> x;
            c[i][j] = x;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0)
                R[i][j] = c[i][j] == 'R' ? 1 : 0;
            else
                R[i][j] = c[i][j] == 'R' ? min3(R[i-1][j-1], R[i][j-1], R[i-1][j])+1 : 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = m-1; j >= 0; j--) {
            if (i == 0 || j == m-1)
                G[i][j] = c[i][j] == 'G' ? 1 : 0;
            else
                G[i][j] = c[i][j] == 'G' ? min3(G[i-1][j+1], G[i][j+1], G[i-1][j])+1 : 0;
        }
    for (int i = n-1; i >= 0; i--)
        for (int j = m-1; j >= 0; j--) {
            if (i == n-1 || j == m-1)
                B[i][j] = c[i][j] == 'B' ? 1 : 0;
            else
                B[i][j] = c[i][j] == 'B' ? min3(B[i+1][j+1], B[i][j+1], B[i+1][j])+1 : 0;
        }
    for (int i = n-1; i >= 0; i--)
        for (int j = 0; j < m; j++) {
            if (i == n-1 || j == 0)
                Y[i][j] = c[i][j] == 'Y' ? 1 : 0;
            else
                Y[i][j] = c[i][j] == 'Y' ? min3(Y[i+1][j-1], Y[i][j-1], Y[i+1][j])+1 : 0;
        }
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m-1; j++)
            s[i][j] = min4(R[i][j], G[i][j+1], B[i+1][j+1], Y[i+1][j]);

    for (int ir=0;ir<n;ir++)
    {
      for (int ic=0;ic<m;ic++)
        table[ 0 ][ ir ][ 0 ][ ic ] = s[ ir ][ ic ];
           
      for (int jc=1;jc<=log2(m);jc++)
        for (int ic=0;ic+(1<<(jc-1))<m;ic++)
         table[0 ][ir ][jc ][ic ] = max(table[0 ][ir ][jc-1 ][ic ],table[0 ][ir ][ jc-1 ][ ic+(1<<(jc-1)) ]);
    }
    // debug("hi");

    for (int jr=1;jr<=log2(n);jr++)
      for(int ir=0;ir<n;ir++)
        for(int jc=0;jc<=log2(m);jc++)
          for(int ic=0;ic<m;ic++)
            table[jr ][ir ][jc ][ic ] = max(table[jr-1 ][ir ][jc ][ic ],table[jr-1 ][ir+(1<<(jr-1)) ][jc ][ic ]);
    // debug("hi");
    // for (int i = 0; i < n-1; i++)
    //     for (int j = 0; j < m-1; j++)
    //         debug(i, j, table[1][i][1][j]);

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;
        x1--, x2--, y1--, y2--;
        int a = 0, b = min(x2-x1+1, y2-y1+1)/2;
        debug(x1, y1, x2, y2, "s");
        while (a < b) {
            int r = (a+b+1)/2;
            int f = query(x1+max(0, r-1), y1+max(0, r-1), x2-r, y2-r);
            debug(r, f);
            if (f >= r) {
                a = r;
            } else {
                b = r-1;
            }
        }
        cout << 4*a*a << "\n";
    }
}