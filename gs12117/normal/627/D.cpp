#include<stdio.h>
int n,m;
int a[200100];
int edge[200100][2];
int en[200100];
int elist[400100];
int root[200100];
int chk[200100];
int dv[200100];
int sn[200100];
int dsn[200100];
int ops[200100];
int mdx[200100];
int mdxl[200100];
int smdx[200100];
int mav;
int fg;
void dfs(int x){
	int i;
	chk[x]=1;
	sn[x]=dv[x];
	ops[x]=dv[x];
	for(i=en[x];i<en[x+1];i++){
		if(chk[elist[i]]==0){
			root[elist[i]]=x;
			dfs(elist[i]);
		}
	}
	for(i=en[x];i<en[x+1];i++){
		if(root[elist[i]]==x){
			if(ops[elist[i]]==1){
				sn[x]+=sn[elist[i]];
			}
			else{
				ops[x]=0;
			}
		}
	}
	dsn[x]=0;
	for(i=en[x];i<en[x+1];i++){
		if(root[elist[i]]==x){
			if(ops[elist[i]]==0&&dsn[x]<dsn[elist[i]]){
				dsn[x]=dsn[elist[i]];
			}
		}
	}
	dsn[x]+=sn[x];
	if(dv[x]==0){
		sn[x]=0;
		dsn[x]=0;
	}
}
void bdfs(int x,int y){
	int i;
	chk[x]=1;
	if(fg<dsn[x])fg=dsn[x];
	if(fg<sn[x]+y)fg=sn[x]+y;
	if(dv[x]==0){
		for(i=en[x];i<en[x+1];i++){
			if(chk[elist[i]]==0){
				bdfs(elist[i],0);
			}
		}
	}
	else{
		mdx[x]=y;
		mdxl[x]=-1;
		smdx[x]=0;
		for(i=en[x];i<en[x+1];i++){
			if(chk[elist[i]]==0&&ops[elist[i]]==0){
				if(mdx[x]<dsn[elist[i]]){
					smdx[x]=mdx[x];
					mdx[x]=dsn[elist[i]];
					mdxl[x]=elist[i];
				}
				else if(smdx[x]<dsn[elist[i]]){
					smdx[x]=dsn[elist[i]];
				}
			}
		}
		for(i=en[x];i<en[x+1];i++){
			if(chk[elist[i]]==0&&ops[elist[i]]==0){
				if(elist[i]!=mdxl[x])bdfs(elist[i],mdx[x]+sn[x]);
				else bdfs(elist[i],smdx[x]+sn[x]);
			}
		}
	}
}
int para(int x){
	int i,j;
	for(i=1;i<=n;i++){
		if(a[i]<x)dv[i]=0;
		else dv[i]=1;
		chk[i]=0;
	}
	root[mav]=0;
	dfs(mav);
	fg=0;
	for(i=1;i<=n;i++){
		chk[i]=0;
	}
	bdfs(mav,0);
	if(fg>=m)return 1;
	return 0;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	mav=1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[mav])mav=i;
	}
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+7;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<n-1;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][1]+1]++;
	}
	j=0;
	for(i=23;i>=0;i--){
		j+=1<<i;
		if(para(j)==0)j-=1<<i;
	}
	printf("%d",j);
	return 0;
}