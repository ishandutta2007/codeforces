#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],b[N],List[N];ll qz1[N],qz2[N];

struct ques{
	int l,r;
}g[2*N];

vector<int> B[N];int fa[N],du[N];bool bk[N];
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		
		qz1[0]=qz2[0]=0;
		for(int i=1;i<=n;i++){
			qz1[i]=qz1[i-1]+a[i];
			qz2[i]=qz2[i-1]+b[i];
		}
		
		for(int i=0;i<=n+1;i++) bk[i]=false,fa[i]=i;
		for(int i=0;i<=n;i++)
			if(qz1[i]==qz2[i]){
				bk[i]=true;
				fa[i]=Find(i+1);
			}
				
		int st=0,ed=0;
		for(int i=1;i<=m;i++) du[i]=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&g[i].l,&g[i].r);
			g[i].l--;du[i]=2;
			if(bk[g[i].l]) du[i]--;
			if(bk[g[i].r]) du[i]--;
			if(du[i]==0) List[++ed]=i;
			B[g[i].l].push_back(i);
			B[g[i].r].push_back(i);
		}
		
		while(st<ed){
			int x=List[++st];
			for(int i=g[x].l;i<=g[x].r;i++){
				i=Find(i);
				if(i>g[x].r) break;
				bk[i]=true;
				for(auto y:B[i]){
					du[y]--;
					if(du[y]==0) List[++ed]=y;
				}
				fa[i]=Find(i+1);
			}
		}
		
		bool pd=true;
		for(int i=1;i<=n;i++)
			if(!bk[i]&&a[i]!=b[i]) {pd=false;break;}
		
		if(pd) printf("YES\n");
		else printf("NO\n");
		
		for(int i=0;i<=n+1;i++) B[i].clear();
	}
	
	return 0;
}