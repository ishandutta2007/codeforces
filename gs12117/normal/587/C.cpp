#include<stdio.h>
int n,m,q;
int edge[100100][2];
int en[100100];
int elist[200100];
int chk[100100];
int dep[100100];
int prt[100100];
int lca[100100][20];
int qry[100100][3];
struct p{
	int x;
	int a[12];
	p operator+(p r){
		int i,j,k;
		p res;
		a[x]=999999999;
		r.a[r.x]=999999999;
		res.x=x+r.x;
		if(res.x>10)res.x=10;
		i=0;
		j=0;
		for(k=0;k<res.x;k++){
			if(a[i]<r.a[j]){
				res.a[k]=a[i];
				i++;
			}
			else{
				res.a[k]=r.a[j];
				j++;
			}
		}
		return res;
	}
};
p cm[100100][20];
void dfs(int loc){
	int i;
	chk[loc]=1;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==0){
			prt[elist[i]]=loc;
			dep[elist[i]]=dep[loc]+1;
			dfs(elist[i]);
		}
	}
}
int lcm(int x,int y){
	int i,t;
	if(dep[x]<dep[y]){
		t=x;
		x=y;
		y=t;
	}
	for(i=0;i<18;i++){
		if(((dep[x]-dep[y])>>i)%2!=0){
			x=lca[x][i];
		}
	}
	for(i=17;i>=0;i--){
		if(lca[x][i]!=lca[y][i]){
			x=lca[x][i];
			y=lca[y][i];
		}
	}
	while(x!=y){
		x=lca[x][0];
		y=lca[y][0];
	}
	return dep[x];
}
p pup(int x,int y){
	int i,s;
	p d;
	d.x=0;
	s=dep[x]-y;
	for(i=18;i>=0;i--){
		if((s>>i)%2!=0){
			d=d+cm[x][i];
			x=lca[x][i];
		}
	}
	return d;
}
int main(){
	int i,j,t;
	p d;
	scanf("%d%d%d",&n,&m,&q);
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
	dep[1]=1;
	dfs(1);
	for(i=1;i<=n;i++){
		lca[i][0]=prt[i];
	}
	for(i=0;i<18;i++){
		for(j=1;j<=n;j++){
			lca[j][i+1]=lca[lca[j][i]][i];
		}
	}
	for(i=0;i<=n;i++){
		cm[i][0].x=0;
	}
	for(i=0;i<m;i++){
		scanf("%d",&t);
		d.x=1;
		d.a[0]=i;
		cm[t][0]=cm[t][0]+d;
	}
	for(i=0;i<18;i++){
		for(j=1;j<=n;j++){
			cm[j][i+1]=cm[j][i]+cm[lca[j][i]][i];
		}
	}
	for(i=0;i<q;i++){
		scanf("%d%d%d",&qry[i][0],&qry[i][1],&qry[i][2]);
		t=lcm(qry[i][0],qry[i][1]);
		d=pup(qry[i][0],t-1)+pup(qry[i][1],t);
		if(d.x>qry[i][2])d.x=qry[i][2];
		printf("%d ",d.x);
		for(j=0;j<d.x;j++){
			printf("%d ",d.a[j]+1);
		}
		printf("\n");
	}
	return 0;
}