#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N][N],Max[N][N][11][11],Log[N];
int qry(int x1,int y1,int x2,int y2) {
	int L1=Log[x2-x1+1],L2=Log[y2-y1+1];
	return	max(max(Max[x1][y1][L1][L2],Max[x2-(1<<L1)+1][y1][L1][L2]),
			max(Max[x1][y2-(1<<L2)+1][L1][L2],Max[x2-(1<<L1)+1][y2-(1<<L2)+1][L1][L2]));
}
int main() {
	int n,m,q,x1,x2,y1,y2;
	scanf("%d%d",&n,&m);
	Log[1]=0;
	for(int i=2;i<=1000;i++)
		Log[i]=Log[i/2]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			scanf("%d",a[i]+j);
			if(a[i][j])a[i][j]=min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1])+1;
			Max[i][j][0][0]=a[i][j];
		}
	for(int b=1;b<10;b++)
		for(int i=1;i<=n;i++)//ljwkwjehsgvdrlkfew
			for(int j=1;j+(1<<b)-1<=m;j++)
				Max[i][j][0][b]=max(Max[i][j][0][b-1],Max[i][j+(1<<(b-1))][0][b-1]);
	for(int a=1;a<10;a++)
		for(int b=0;b<10;b++)
			for(int i=1;i+(1<<a)-1<=n;i++)
				for(int j=1;j+(1<<b)-1<=m;j++)
					Max[i][j][a][b]=max(Max[i][j][a-1][b],Max[i+(1<<(a-1))][j][a-1][b]);
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int L=1,R=min(x2-x1+1,y2-y1+1);
		while(L<=R) {
			int mid=(L+R)>>1;
			if(qry(x1+mid-1,y1+mid-1,x2,y2)>=mid)L=mid+1;
			else R=mid-1;
		}
		printf("%d\n",L-1);
	}
	return 0;
}