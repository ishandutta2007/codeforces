#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define PB push_back

const int MAXN=510;
const int MAXQ=600010;
const int MAXLen=30;
const int MAXCnt=MAXN/MAXLen+2;

char ground[MAXN][MAXN];
int rows, cols;
int qx[MAXQ], qy[MAXQ]; bool qans[MAXQ];
vector<int> q[MAXN][MAXN];
int queries;

int bx[MAXN], by[MAXN], cnt;
int p1[MAXN][MAXN][MAXCnt];
int p2[MAXN][MAXN][MAXCnt];

void solve(int r1, int r2) {
	if(r1>r2) return;
	int rmid=(r1+r2)/2;
	for(int i=r1; i<=r2; ++i)
		for(int j=1; j<=cols; ++j)
			for(int c=0; c<cnt; ++c)
				p1[i][j][c]=p2[i][j][c]=0;
	for(int j=1; j<=cols; ++j)
		if(ground[rmid][j]=='.') {
			p1[rmid][j][bx[j]]|=by[j];
			p2[rmid][j][bx[j]]|=by[j];
		}
	for(int i=rmid; i>=r1; --i)
		for(int j=cols; j>=1; --j) {
			if(ground[i][j]=='#') continue;
			if(i<rmid) for(int c=0; c<cnt; ++c)
				p1[i][j][c]|=p1[i+1][j][c];
			if(j<cols) for(int c=0; c<cnt; ++c)
				p1[i][j][c]|=p1[i][j+1][c];
		}
	for(int i=rmid; i<=r2; ++i)
		for(int j=1; j<=cols; ++j) {
			if(ground[i][j]=='#') continue;
			if(i>rmid) for(int c=0; c<cnt; ++c)
				p2[i][j][c]|=p2[i-1][j][c];
			if(j>1) for(int c=0; c<cnt; ++c)
				p2[i][j][c]|=p2[i][j-1][c];
		}
	for(int i=r1; i<=rmid; ++i)
		for(int j=1; j<=cols; ++j)
			for(int k=0; k<(int)q[i][j].size(); ++k) {
				int cur=q[i][j][k];
				int x2=qx[cur], y2=qy[cur];
				if(rmid<=x2 && x2<=r2) {
					bool flag=false;
					for(int c=0; c<cnt; ++c)
						if(p1[i][j][c]&p2[x2][y2][c])
							flag=true;
					qans[cur]=flag;
				}
			}
	solve(r1, rmid-1);
	solve(rmid+1, r2);
}

int main() {
	scanf("%d%d", &rows, &cols);
	for(int i=1; i<=rows; ++i)
		scanf("%s", ground[i]+1);
	scanf("%d", &queries);
	for(int i=1; i<=rows; ++i)
		for(int j=1; j<=cols; ++j)
			q[i][j].clear();
	for(int i=1; i<=queries; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		qx[i]=x2, qy[i]=y2;
		q[x1][y1].PB(i);
	}

	cnt=1; int curb=0;
	for(int j=1; j<=cols; ++j) {
		if(curb==MAXLen) ++cnt, curb=0;
		bx[j]=cnt-1, by[j]=(1<<curb);
		++curb;
	}

	solve(1, rows);
	for(int i=1; i<=queries; ++i)
		printf("%s\n", qans[i]?"Yes":"No");
	return 0;
}