#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,b[200005],sum[200005],t[200005],ts[200005],nxt[10000005],tot=0,h[9999992],I[10000005],cl[9999992];
ll val[10000005];
vector<int> vec[200005];
int Ins(ll x,int id){
	int p=x%9999991;
	for(int i=h[p];i;i=nxt[i])if(val[i]==x)return I[i];
	if(!h[p])h[p]=++tot,cl[++cl[0]]=p;
	else {
		int i;
		for(i=h[p];nxt[i];i=nxt[i]);
		nxt[i]=++tot;
	}
	I[tot]=id,val[tot]=x;
	return 0;
}
int main() {
	int tc;
	cin>>tc;
	while(tc--) {
		cin>>n,b[0]=0;
		int m=0,flag=0,sss=0;
		for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]),vec[i].clear(),sss+=sum[i];	
			for(int j=1,x;j<=sum[i];j++)scanf("%d",&x),vec[i].push_back(x);
		}
		sss=sqrt(sss)+1;
		sss/=5;
		sss=max(sss,1);
		//sss=4;
		for(int i=1;i<=n;i++){
			if(sum[i]<=sss){
				sort(vec[i].begin(),vec[i].end());
				for(int j=0;j<sum[i]&&!flag;j++){
					for(int k=j+1;k<sum[i];k++){
						int p=Ins(1000000007ll*vec[i][j]+vec[i][k],i);
						if(p){
							printf("%d %d\n",p,i);
							flag=1;
							break;
						}
					}
				}
			}
			else {
				t[++m]=i;
			}
			for(int j=1;j<=sum[i];j++)b[++b[0]]=vec[i][j-1];
		}
		sort(b+1,b+b[0]+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sum[i];j++)vec[i][j-1]=lower_bound(b+1,b+b[0]+1,vec[i][j-1])-b;
		}
		for(int p=1;p<=m&&!flag;p++){
			int i=t[p];
			for(int t1=0;t1<sum[i];t1++)ts[vec[i][t1]]=1;
			for(int q=1;q<=n&&!flag;q++){
				int j=q,u=0;
				if(i==j)continue;
				for(int t1=0;t1<sum[j];t1++)u+=ts[vec[j][t1]];
				if(u>1){
					printf("%d %d\n",i,j);
					flag=1;
				}
			}
			for(int t1=0;t1<sum[i];t1++)ts[vec[i][t1]]=0;
		}
		if(!flag)puts("-1");
		for(int i=1;i<=cl[0];i++)h[cl[i]]=0;
		for(int i=1;i<=tot;i++)I[i]=nxt[i]=val[i]=0;
		cl[0]=tot=0;
	}
}