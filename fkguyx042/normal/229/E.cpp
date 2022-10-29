#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int N=1005,M=1005,K=1005;
int n,m,cnt,lim;
vector<int> c[M];
int ord[K],*top=ord;
double f[M][N];
double C[K][K];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int k; scanf("%d",&k);
		while(k--){
			int x; scanf("%d",&x);
			*top++=x;
			c[i].push_back(x);
		}
		sort(c[i].begin(),c[i].end(),greater<int>());
	}
	sort(ord,top,greater<int>());
	for(int i=0;i<K;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=j?C[i-1][j]+C[i-1][j-1]:1;
	lim=n<top-ord?ord[n]:2e9;
	for(int i=n-1;i>=0;i--)
		if(ord[i]==lim) cnt++;
		else break;
	f[0][0]=1;
	int ttt=0;
	for(int i=1;i<=m;i++){
		int k=lower_bound(c[i].begin(),c[i].end(),lim,greater<int>())-c[i].begin();
		bool tmp=k<c[i].size()&&c[i][k]==lim;
		ttt+=tmp;
		for(int j=0;j<=cnt&&j<=i;j++)
			f[i][j]=f[i-1][j]/C[c[i].size()][k]+(j&&tmp?f[i-1][j-1]/C[c[i].size()][k+1]:0);
	}
	printf("%.12lf\n",f[m][cnt]/C[ttt][cnt]);
}