#include<bits/stdc++.h>
using namespace std;

const int N=1e6+100,maxn=1e6;
bool bk[N];int pri[N],b[20],List[20],cnt=0,g[N],Min[N][2];

vector<int> p[N];bool vis[20][2],vis2[N];

int Ans2=0,Anss[N],Ans[N][16];
void dfs(int k,int s){
	if(k>cnt){
		int ti=0;
		if(s==0) ti=0;
		else if(s==1) ti=1;
		else if(s==2) ti=0;
		else ti=s-2;
		while(ti--){
			Ans2++;
			if(s==1||s%2==0) Anss[Ans2]=0;
			else Anss[Ans2]=1;
			for(int j=1;j<=cnt;j++)
				if(b[j]) Ans[Ans2][++Ans[Ans2][0]]=List[j];
		}
		return ;
	}
	b[k]=1;dfs(k+1,s+1);
	b[k]=0;dfs(k+1,s);
}

int a[N],sta[N],tot=0;

bool cmp(int n1,int n2) {return (n1<n2);}
int main()
{
	
	memset(bk,true,sizeof(bk));
	for(int i=2;i<=maxn;i++){
		if(bk[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0];j++){
			if(maxn/i<pri[j]) break;
			bk[i*pri[j]]=false;
			if(i%pri[j]==0) break;
		}
	}
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=pri[0];i++) g[pri[i]]=n;
	for(int i=1;i<=n;i++){
		int t=sqrt(a[i]),e=a[i];
		for(int j=1;j<=pri[0];j++){
			if(a[i]/pri[j]<pri[j]) break;
			if(e%pri[j]==0){
				int Sum=0;
				while(e%pri[j]==0) e/=pri[j],Sum++;
				p[pri[j]].push_back(Sum);
				g[pri[j]]--;
			}
		}
		if(e>1){
			p[e].push_back(1);
			g[e]--;
		}
	}
	
	for(int i=1;i<=pri[0];i++){
		if(g[pri[i]]<=1){
			sort(p[pri[i]].begin(),p[pri[i]].end(),cmp);
			if(g[pri[i]]==1) Min[i][0]=0,Min[i][1]=p[pri[i]][0];
			else Min[i][0]=p[pri[i]][0],Min[i][1]=p[pri[i]][1];
			sta[++tot]=i;
		}
		else Min[i][0]=Min[i][1]=0;
	}
	
	memset(vis2,true,sizeof(vis2));
	memset(vis,true,sizeof(vis));
	for(int i=1;i<=n;i++){
		bool pd=false;
		for(int j=1;j<=tot;j++){
			int e=a[i],Sum=0;
			while(e%pri[sta[j]]==0) e/=pri[sta[j]],Sum++;
			if(Sum==Min[sta[j]][0]&&vis[j][0]) pd=true,vis[j][0]=false;
			else if(Sum==Min[sta[j]][1]&&vis[j][1]) pd=true,vis[j][1]=false;
		}
		if(pd) List[++cnt]=i,vis2[i]=false;
	}
	
	for(int i=1;i<=pri[0];i++){
		bool pd1=true,pd2=true;
		for(int j=1;j<=cnt;j++){
			int e=a[List[j]],Sum=0;
			while(e%pri[i]==0) e/=pri[i],Sum++;
			if(Sum==Min[i][0]&&pd1) pd1=false;
			else if(Sum==Min[i][1]&&pd2) pd2=false;
		}
		if(pd1||pd2){
			for(int j=1;j<=n;j++){
				if(!vis2[j]) continue;
				int e=a[j],Sum=0;bool pd=false;
				while(e%pri[i]==0) e/=pri[i],Sum++;
				if(Sum==Min[i][0]&&pd1) pd1=false,pd=true;
				else if(Sum==Min[i][1]&&pd2) pd2=false,pd=true;
				if(pd) List[++cnt]=j,vis2[j]=false;
			}
		}
	}
	
	dfs(1,0);
	
	printf("%d\n",Ans2);
	for(int i=1;i<=Ans2;i++){
		sort(Ans[i]+1,Ans[i]+Ans[i][0]+1,cmp);
		printf("%d ",Anss[i]);
		printf("%d ",Ans[i][0]);
		for(int j=1;j<=Ans[i][0];j++) printf("%d ",Ans[i][j]);
		printf("\n");
	}
	
	return 0;
}