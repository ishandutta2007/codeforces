#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int ri[1100][1100];
int dn[1100][1100];
int sq[1100][1100];

int table[10][1100][10][1100];
int n, m;

int query(int x1, int y1, int x2, int y2) {
	int lenx=x2-x1+1;
	int kx = 0;
	while (1<<(kx+1) <= lenx) kx++;

    int leny=y2-y1+1;
    int ky = 0;
    while (1<<(ky+1) <= leny) ky++;

    int max_R1 = max ( table[kx ][x1 ][ky ][y1 ] , table[kx ][x1 ][ky ][ y2+1- (1<<ky) ] );
  	int max_R2 = max ( table[kx ][x2+1-(1<<kx) ][ky ][y1 ], table[kx ][x2+1- (1<<kx) ][ky ][y2+1- (1<<ky) ] );
  	return max ( max_R1, max_R2 );
}

void solve() {
	scanf("%d %d", &n, &m);

	REP(i,n) REP(j,m) {
		scanf("%d", &sq[i][j]);
	}	

	for (int i = n-1; i >= 0; i--) {
		for (int j = m-1; j >= 0; j--) {
			if (sq[i][j]==1) {
				ri[i][j] = ri[i][j+1] + 1;
				dn[i][j] = dn[i+1][j] + 1;
				sq[i][j] = min(ri[i][j], min(dn[i][j], sq[i+1][j+1] + 1));
			}
			else sq[i][j] = 0;
		}
	}

	for (int ir = 0; ir < n; ir++) {
		for(int ic=0;ic<m;ic++)
	    	table[ 0 ][ ir ][ 0 ][ ic ] = sq[ir][ic];
	       
	  	for(int jc=1;jc<=10;jc++) {
	  		for(int ic=0; ic+(1<<(jc)) <= m; ic++) {
	     		table[0 ][ir ][jc ][ic ] = max(table[0 ][ir ][jc-1 ][ic ],table[0 ][ir ][ jc-1 ][ ic+ (1<<(jc-1)) ]);
	    	}
		}
	}       

	for (int jr = 1; jr <= 10; jr++) {
		for (int ir = 0; ir+(1<<(jr)) <= n; ir++) {
			for (int jc = 0; jc <= 10; jc++) {
				for (int ic = 0; ic < m; ic++) {
					table[jr][ir][jc][ic] = max(table[jr-1][ir][jc][ic],table[jr-1][ir+(1<<(jr-1)) ][jc ][ic ])  ;
				}
			}
		}
	}
		
	int t;
	for (scanf("%d", &t); t; t--) {
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); x1--; y1--; x2--; y2--;

		int st = 0, ed = min(x2-x1+1, y2-y1+1);
		while (st < ed) {
			int md = (st+ed+1)/2;
			if (query(x1, y1, x2-md+1, y2-md+1) >= md) st=md;
			else ed = md-1;
		}

		printf("%d\n", st);
	}

}


int main() {
    solve();
}