#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

int n,Q,sn[200005][11],a[200005];
int be[200005],size,tmp,stk[11],In[500005],top,gtw;

void dfs(int x,int v,int k){
	if(x>top){
		if(gtw==-1) In[k]+=gtw;
		tmp+=v*In[k];
		if(gtw==1) In[k]+=gtw;
		return;
	}
	dfs(x+1,v,k);
	dfs(x+1,-v,k*stk[x]);
}

long long ans;

void add(int x,int y){
	tmp=0; gtw=y;
	top=sn[x][0];
	For(i,1,top) stk[i]=sn[x][i];
	dfs(1,1,1);
	ans+=y*tmp;
	size+=y;
}

int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		a[i]=x;
		for(int j=2;j*j<=x;j++){
			if(x%j)continue;
			sn[i][++*sn[i]]=j;
			while(x%j==0) x/=j;
		}
		if(x>1) sn[i][++*sn[i]]=x;
	}
	For(i,1,n) be[i]=1;
	For(i,1,Q){
		int x;
		scanf("%d",&x);
		add(x,be[x]);
		be[x]*=-1;
		printf("%I64d\n",ans);
	}
	return 0;
}