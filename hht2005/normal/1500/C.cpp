#include<bits/stdc++.h>
using namespace std;
const int N=1510;
vector<int>x,pos[N],S[N*2],ans;
map<vector<int>,int>f;
int a[N][N],b[N][N],deg[N*2],q[N],cc[N];
int main() {
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",a[i]+j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",b[i]+j);
	for(int i=1;i<=n;i++) {
		a[i][m+1]=i;
		x.clear();
		for(int j=1;j<=m;j++)
			x.push_back(a[i][j]);
		if(!f[x])f[x]=++cnt;
		pos[f[x]].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		x.clear();
		for(int j=1;j<=m;j++)
			x.push_back(b[i][j]);
		int t=f[x];
		if(!t) {puts("-1");return 0;}
		else {
			if(cc[t]==int(pos[t].size())) {puts("-1");return 0;}
			b[i][m+1]=pos[t][cc[t]++];
		}
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=m+1;j++) {
			if(b[i][j]>b[i+1][j])S[i].push_back(j+n),deg[j+n]++;
			else if(b[i][j]<b[i+1][j])S[j+n].push_back(i),deg[i]++;
		}
	int h=1,e=0;
	for(int i=1;i<=m+1;i++)
		if(!deg[i+n])q[++e]=i+n;
	while(h<=e) {
		int x=q[h++];
		if(x>n) {
			ans.push_back(x-n);
			for(int y:S[x])
				if(deg[y])deg[y]=0,q[++e]=y;
		} else {
			for(int y:S[x]) {
				deg[y]--;
				if(!deg[y])deg[y]=0,q[++e]=y;
			}
		}
		if(deg[n+m+1]==0)break;
	}
	if(deg[n+m+1]==0) {
		cout<<ans.size()<<endl;
		for(int i=ans.size()-1;i>=0;i--)
			printf("%d ",ans[i]);
	} else puts("-1");
	return 0;
}