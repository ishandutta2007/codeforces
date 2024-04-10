#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2010;
int n,mod;

vector<int> B[N];
int f[N][N],fa[N],Ans[N],sta[N],qz[N][N],qz1[N][N],qz2[N][N];bool bk[N];

void dfs(int x){
	bk[x]=false;
	for(auto y:B[x])
		if(bk[y]){
			fa[y]=x;
			dfs(y);
		}
	int tot=0;
	for(auto y:B[x])
		if(fa[y]==x) sta[++tot]=y;
	
	for(int i=1;i<=n;i++)
		qz1[0][i]=qz2[tot+1][i]=1;
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=n;j++)
			qz1[i][j]=(ll)qz1[i-1][j]*qz[sta[i]][j]%mod;
	for(int i=tot;i>=1;i--)
		for(int j=1;j<=n;j++)
			qz2[i][j]=(ll)qz2[i+1][j]*qz[sta[i]][j]%mod;
	for(int i=1;i<=tot;i++){
		int Sum=0;
		for(int j=2;j<=n;j++){
			Sum=(Sum+(ll)qz1[i-1][j-1]*qz2[i+1][j-1])%mod;
			f[x][j]=(f[x][j]+(ll)Sum*f[sta[i]][j])%mod;
		}
	}
	for(int i=1;i<=n;i++) f[x][i]=(f[x][i]+qz1[tot][i])%mod;
	for(int i=1;i<=n;i++) qz[x][i]=(qz[x][i-1]+f[x][i])%mod;
	
	if(x==1){
		for(int i=1;i<n;i++) Ans[i]=(Ans[i]+qz1[tot][i])%mod;
	}
	
}

int C[N][N];

int main()
{
	
	scanf("%d%d",&n,&mod);
	
	for(int i=0;i<=n;i++) C[i][0]=C[i][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		B[x].push_back(y);
		B[y].push_back(x);
	}
	
	memset(bk,true,sizeof(bk));
	dfs(1);
	
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<i;j++){
			int t=(ll)Ans[j]*C[i][j]%mod;
			if((i-j)%2==1) Ans[i]=(Ans[i]-t+mod)%mod;
			else Ans[i]=(Ans[i]+t)%mod;
		}
	
	for(int i=1;i<n;i++) printf("%d ",Ans[i]);
	printf("\n");
	
	return 0;
}