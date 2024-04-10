#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define int64 long long
#define N 100010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m;
int a[N];
int64 an,zhi;
VI b[N];
int main() {
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d",&a[i]);
	For(i,1,m-1) {
		an+=abs(a[i+1]-a[i]);
		if (a[i]!=a[i+1]) {
			b[a[i]].push_back(a[i+1]);
			b[a[i+1]].push_back(a[i]);
		}
	}
	zhi=an;
	For(i,1,n) if (b[i].size()) {
		sort(b[i].begin(),b[i].end());
		int A=b[i][b[i].size()/2];
		int64 re=an;
		for (j=0;j<b[i].size();j++) re=re-abs(i-b[i][j])+abs(A-b[i][j]);
		zhi=min(zhi,re);
	}
	printf("%I64d\n",zhi);
	return 0;
}