#include<bits/stdc++.h>
using namespace std;

const int N=110;
vector<int> B[N];bool bk[N],vis[N];int fa[N],sta[N],tot,si[N],f[N][N],p[N][N],sta2[N],g[N];

void dfs(int x){
	bk[x]=false;
	int Max=0;
	for(auto y:B[x])
		if(bk[y]){
			fa[y]=x;
			dfs(y);
			if(Max<si[y]) Max=si[y];
		}
	tot=0;
	for(auto y:B[x])
		if(fa[y]==x) sta[++tot]=y;
	for(int i=1;i<=tot;i++) p[0][i]=sta[i];
	
	for(int i=0;i<=tot+Max;i++){
		int Sum1=0,Sum2=0;
		for(int j=1;j<=tot;j++)
			if(f[sta[j]][i]==0) Sum1++;
		Sum2=tot;
		for(int j=tot;j>=1;j--){
			if(f[p[i][j]][i]==1) p[i+1][Sum2--]=p[i][j];
			else p[i+1][Sum1--]=p[i][j];
		}
	}
	
	if(x==1){
		x++;x--;
	}
	
	si[x]=tot+Max;
	for(int i=1;i<=tot;i++) vis[sta[i]]=true;
	for(int i=tot+Max;i>=0;i--){
		int Sum2=0;
		for(int j=1;j<=tot;j++)
			if(vis[sta[j]]&&f[sta[j]][i]) Sum2++;
		if(Sum2==0){
			bool pd=true;int tot2=0;
			for(int j=i-1;j>=0;j--){
				int Sum3=0;
				for(int k=1;k<=tot;k++)
					if(vis[sta[k]]) Sum3+=f[sta[k]][j];
				if(!Sum3){
					for(int k=tot;k>=1;k--){
						if(vis[p[j][k]]){
							sta2[++tot2]=p[j][k];
							vis[p[j][k]]=false;
							break;
						}
					}
				}
				else if(Sum3>=2) {pd=false;break;}
			}
			for(int k=1;k<=tot;k++)
				if(vis[sta[k]]) {pd=false;break;}
			
			for(int j=1;j<=tot2;j++) vis[sta2[j]]=true;
			if(!pd){
				f[x][i]=1;
				for(int k=tot;k>=1;k--)
					if(vis[p[i][k]]){
						g[p[i][k]]=i;
						vis[p[i][k]]=false;
						break;
					}
			}
		}
		else f[x][i]=1;
	}
	while(si[x]&&f[x][si[x]]==0) si[x]--;
}

int Ans;
void dfs2(int x,int c){
	bk[x]=false;sta[++tot]=x;
	if(g[x]==c) Ans=x;
	for(auto y:B[x]){
		if(bk[y]){
			dfs2(y,c);
		}
	}
}

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		B[x].push_back(y);
		B[y].push_back(x);
	}
	
	memset(bk,true,sizeof(bk));
	dfs(1);
	
	int lim=si[1];
	for(int i=2;i<=n;i++) g[i]=lim-g[i];
	
	memset(bk,true,sizeof(bk));
	int now=1;
	for(int i=0;i<=lim+1;i++){
		tot=0;Ans=-1;dfs2(now,i);
		for(int j=1;j<=tot;j++) bk[sta[j]]=true;
		if(Ans==-1){
			printf("! %d\n",now);
			fflush(stdout);
			return 0;
		}
		else{
			printf("? %d %d\n",Ans,fa[Ans]);
			fflush(stdout);
			int t;scanf("%d",&t);
			if(t==Ans) bk[fa[Ans]]=false,now=Ans;
			else now=fa[Ans],bk[Ans]=false;
		}
	}
	
	return 0;
}