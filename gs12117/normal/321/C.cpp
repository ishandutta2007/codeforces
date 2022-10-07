#include<stdio.h>
int n;
int es[100100];
int elist[200100];
int root[100100];
int rank[100100];
int chk[100100];
int under[100100];
int edge[100100][2];
char op[100100];
int findv;
void dfs(int loc,int dep){
	chk[loc]=1;
	rank[loc]=dep;
	under[loc]=1;
	int i;
	for(i=es[loc];i<es[loc+1];i++){
		if(chk[elist[i]]==0){
			root[elist[i]]=loc;
			dfs(elist[i],dep+1);
			under[loc]+=under[elist[i]];
		}
	}
}
void vdfs(int loc,int ch){
	chk[loc]=ch;
	under[loc]=1;
	int i;
	for(i=es[loc];i<es[loc+1];i++){
		if(elist[i]!=root[loc]&&op[elist[i]]==0){
			vdfs(elist[i],ch);
			under[loc]+=under[elist[i]];
		}
	}
}
void fdfs(int loc,int ch){
	int i;
	if(under[loc]<ch)return;
	findv=loc;
	for(i=es[loc];i<es[loc+1];i++){
		if(elist[i]!=root[loc]&&op[elist[i]]==0&&under[loc]>=ch){
			fdfs(elist[i],ch);
		}
	}
}
void solve(int loc,char sol){
	vdfs(loc,loc);
	fdfs(loc,(under[loc]+1)/2);
	op[findv]=sol;
	int t=findv;
	if(findv!=loc)solve(loc,sol+1);
	loc=t;
	int i;
	for(i=es[loc];i<es[loc+1];i++){
		if(elist[i]!=root[loc]&&op[elist[i]]==0){
			solve(elist[i],sol+1);
		}
	}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		es[edge[i][0]+2]++;
		es[edge[i][1]+2]++;
	}
	for(i=0;i<n+7;i++){
		es[i+1]+=es[i];
	}
	for(i=0;i<n-1;i++){
		elist[es[edge[i][0]+1]]=edge[i][1];
		es[edge[i][0]+1]++;
		elist[es[edge[i][1]+1]]=edge[i][0];
		es[edge[i][1]+1]++;
	}
	dfs(1,0);
	solve(1,'A');
	for(i=1;i<=n;i++){
		printf("%c ",op[i]);
	}
}