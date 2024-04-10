#include<stdio.h>
long long int n;
int a[80100][2];
int b[160100];
int es[80100];
int chk[80100];
int root[80100];
long long int snum[80100];
unsigned long long int ans;
void dfs(int loc){
	int i;
	long long int tans=0;
	long long int pnum=0;
	long long int hpnum=0;
	chk[loc]=1;
	snum[loc]=1;
	for(i=es[loc];i<es[loc+1];i++){
		if(b[i]!=root[loc]){
			root[b[i]]=loc;
			dfs(b[i]);
			snum[loc]+=snum[b[i]];
		}
	}
	pnum=n*(n-1)/2;
	for(i=es[loc];i<es[loc+1];i++){
		if(b[i]!=root[loc]){
			pnum-=snum[b[i]]*(snum[b[i]]-1)/2;
		}
	}
	pnum-=(n-snum[loc])*(n-snum[loc]-1)/2;
	hpnum=(snum[loc])*(snum[loc]-1)/2;
	for(i=es[loc];i<es[loc+1];i++){
		if(b[i]!=root[loc]){
			hpnum-=snum[b[i]]*(snum[b[i]]-1)/2;
		}
	}
	tans=(pnum-1)*hpnum;
	tans-=hpnum*(hpnum-1)/2;
	ans-=tans;
}
int main(){
	int i,j;
	scanf("%I64d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		es[a[i][0]+2]++;
		es[a[i][1]+2]++;
	}
	for(i=0;i<n+3;i++){
		es[i+1]+=es[i];
	}
	for(i=0;i<n-1;i++){
		b[es[a[i][0]+1]]=a[i][1];
		b[es[a[i][1]+1]]=a[i][0];
		es[a[i][0]+1]++;
		es[a[i][1]+1]++;
	}
	ans=(n*(n-1)/2);
	ans*=(n*(n-1)/2-1);
	ans/=2;
	dfs(1);
	printf("%I64u",ans*2);
}