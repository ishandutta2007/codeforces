#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

const int st=100005;
const ll INF=1000111222333444555LL;
int n,m,K,low[st],high[st];
ll c[st],t[305][305],RES,tpom[305];
pair<int,int> tab[st];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n+1;++i)
		for(int j=1;j<=n;++j) t[i][j]=INF;
	scanf("%d%d",&m,&K);
	for(int j=0;j<m;++j)scanf("%d%d%I64d",&low[j],&high[j],&c[j]);
	for(int i=1;i<=n;++i){
		for(int k=1;k<=i;++k) tpom[k]=INF;
		for(int j=0;j<m;++j)if(high[j]==i)
			tpom[low[j]]=min(tpom[low[j]],c[j]);
		for(int k=2;k<=i;++k)tpom[k]=min(tpom[k],tpom[k-1]);
		//---
		for(int k=1;k<=i;++k)for(int j=1;j<=k;++j)
			t[i+1][k]=min(t[i+1][k],t[i+1-j][k-j]+tpom[i+1-j]);
		for(int k=1;k<=n;++k)t[i+1][k]=min(t[i+1][k],t[i][k]);
	}
	RES=INF;
	for(int i=1;i<=n+1;++i)
		for(int k=K;k<=n;++k)RES=min(RES,t[i][k]);
	if(RES==INF)printf("-1");
	else printf("%I64d",RES);
	return 0;
}