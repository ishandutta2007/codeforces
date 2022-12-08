#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXTOT=1010;
const int MAXN=1010;

double p[MAXTOT][MAXN];
double ways[MAXTOT][MAXN];
int n, tot;

double cv[MAXN];
double C[MAXN][MAXN];

pair<double, int> all[MAXN];
int allcnt;
int whole[MAXTOT];
int must[MAXTOT];
int but[MAXTOT];

int main() {
	for(int i=0; i<MAXN; ++i) C[i][0]=C[i][i]=1.0;
	for(int i=0; i<MAXN; ++i)
		for(int j=1; j<i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
	scanf("%d%d", &n, &tot);
	allcnt=0;
	for(int i=1; i<=tot; ++i) {
		int ck; scanf("%d", &ck);
		whole[i]=ck;
		for(int j=1; j<=ck; ++j) {
			scanf("%lf", &cv[j]);
			all[++allcnt]=make_pair(cv[j], i);
		}
	}
	sort(all+1, all+allcnt+1);
	int le=allcnt-n+1, ri=le, mid=le;
	while(le>1 && all[le-1].first==all[le].first) --le;
	while(ri<allcnt && all[ri+1].first==all[ri].first) ++ri;
	memset(must, 0, sizeof(must));
	for(int i=ri+1; i<=allcnt; ++i)
		must[all[i].second]++;
	memset(but, 0, sizeof(but));
	for(int i=le; i<=ri; ++i)
		but[all[i].second]++;
	int want=ri-mid+1;
	memset(p, 0, sizeof(p));
	p[0][0]=1.0;
	memset(ways, 0, sizeof(ways));
	ways[0][0]=1.0;
	for(int i=1; i<=tot; ++i) {
		for(int j=0; j<=want; ++j)
			for(int k=0; k<=but[i]; ++k)
				ways[i][j+k]+=ways[i-1][j];
		for(int j=0; j<=want; ++j)
			if(p[i-1][j]>1E-9) {
				for(int k=0; k<=but[i]; ++k) {
					double p0=ways[i-1][j]/ways[i][j+k];
					double p1=1.0/C[whole[i]][must[i]+k];
					p[i][j+k]+=p[i-1][j]*p0*p1;
				}
			}
	}

	printf("%.10lf\n", p[tot][want]);
	return 0;
}