#include<stdio.h>
int n,m;
int da,db;
int ans;
int chk[10];
int sept(int x){
	if(x<=7)return 1;
	return sept((x+6)/7)+1;
}
int f(int x,int y){
	int i;
	for(i=0;i<7;i++){
		chk[i]=0;
	}
	for(i=0;i<da;i++){
		chk[x%7]++;
		x/=7;
	}
	for(i=0;i<db;i++){
		chk[y%7]++;
		y/=7;
	}
	for(i=0;i<7;i++){
		if(chk[i]>1)return 0;
	}
	return 1;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	da=sept(n);
	db=sept(m);
	if(da+db>7)ans=0;
	else{
		ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(f(i,j))ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}