#include<stdio.h>
int n,m;
int edge[100100][3];
int elist[200100][2];
int en[100100];
char tmp[20];
int resn;
int res[100100];
int tresn;
int tres[100100];
int chk[100100];
int root[100100];
int rn[100100];
int rs[100100];
void dfs(int loc,int col,int r){
	if(chk[loc]==1)return;
	chk[loc]=1;
	root[loc]=r;
	res[loc]=col;
	int i;
	for(i=en[loc];i<en[loc+1];i++){
		dfs(elist[i][0],col^elist[i][1],r);
	}
}
void search(){
	int i,j;
	for(i=1;i<=n;i++){
		chk[i]=0;
		rn[i]=0;
		rs[i]=0;
	}
	for(i=1;i<=n;i++){
		if(chk[i]==0)dfs(i,0,i);
	}
	for(i=1;i<=n;i++){
		rn[root[i]]++;
		rs[root[i]]+=res[i];
	}
	for(i=1;i<=n;i++){
		if(root[i]==i){
			if(rn[i]<rs[i]*2){
				res[i]=1;
				rs[i]=rn[i]-rs[i];
			}
		}
	}
	for(i=1;i<=n;i++){
		if(root[i]!=i){
			res[i]^=res[root[i]];
		}
	}
	resn=0;
	for(i=1;i<=n;i++){
		resn+=res[i];
	}
	for(i=1;i<=n;i++){
		for(j=en[i];j<en[i+1];j++){
			if((res[i]^res[elist[j][0]])!=elist[j][1]){
				resn=99999999;
			}
		}
	}
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%s",&edge[i][0],&edge[i][1],tmp);
		if(tmp[0]=='B')edge[i][2]=0;
		else edge[i][2]=1;
	}
	for(i=0;i<m;i++){
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+7;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<m;i++){
		elist[en[edge[i][0]+1]][0]=edge[i][1];
		elist[en[edge[i][0]+1]][1]=edge[i][2];
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]][0]=edge[i][0];
		elist[en[edge[i][1]+1]][1]=edge[i][2];
		en[edge[i][1]+1]++;
	}
	search();
	tresn=resn;
	for(i=1;i<=n;i++){
		tres[i]=res[i];
	}
	for(i=en[1];i<en[n+1];i++){
		elist[i][1]^=1;
	}
	search();
	if(resn<tresn){
		tresn=resn;
		for(i=1;i<=n;i++){
			tres[i]=res[i];
		}
	}
	if(tresn>n)printf("-1");
	else{
		printf("%d\n",tresn);
		for(i=1;i<=n;i++){
			if(tres[i]==1)printf("%d ",i);
		}
	}
	return 0;
}