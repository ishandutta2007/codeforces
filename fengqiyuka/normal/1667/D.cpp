#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
vector<int> B[N];
bool bk[N];int g[N],sta1[N],sta2[N],p[N],Ans[N],tot,fa[N];bool pd;
int mymin(int x,int y) {return (x<y?x:y);}
void dfs(int x){
	bk[x]=false;
	int Sum=0,Sum1=0,Sum2=0;
	for(auto y:B[x]){
		Sum++;
		if(bk[y]){
			fa[y]=x;
			dfs(y);
			if(!pd) return ;
		}
	}
	for(auto y:B[x]){
		if(fa[y]==x){
			if(g[y]==0) sta1[++Sum1]=y;
			else sta2[++Sum2]=y;
		}
	}
	
	p[x]=sta1[Sum1];
	if(Sum%2==1){
		int t=mymin(Sum1,Sum2);
		for(int i=1;i<=t;i++) Ans[++tot]=sta1[i],Ans[++tot]=sta2[i],Ans[++tot]=p[sta2[i]];
		Sum1-=t;Sum2-=t;
		if(Sum1) Ans[++tot]=sta1[t+1],Sum1--;
		if(Sum1>=2||Sum2>=2){
			pd=false;
			return ;
		}
	}
	else{
		int t=mymin(Sum1,Sum2);
		for(int i=1;i<=t;i++) Ans[++tot]=sta2[i],Ans[++tot]=p[sta2[i]],Ans[++tot]=sta1[i];
		Sum1-=t;Sum2-=t;
		if(Sum2) Ans[++tot]=sta2[t+1],Ans[++tot]=p[sta2[t+1]],Sum2--;
		if(Sum1>=2||Sum2>=2){
			pd=false;
			return ;
		}
	}
	if(Sum1) g[x]=1;
	else g[x]=0;
	if(x==1&&(Sum1||Sum2)) pd=false;
}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			B[x].push_back(y);
			B[y].push_back(x);
		}
		
		for(int i=1;i<=n;i++) bk[i]=true;
		tot=0;pd=true;dfs(1);
		
		if(!pd) printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<=tot;i++) printf("%d %d\n",Ans[i],fa[Ans[i]]);
		}
		
		for(int i=1;i<=n;i++) B[i].clear();
	}
	
	return 0;
}