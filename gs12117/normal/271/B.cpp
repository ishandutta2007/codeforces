#include<stdio.h>
int n,m;
int ers[101000];
int mp[101000];
int a[510][510];
int ans;
int main(){
	int i,j,tmp;
	ers[0]=1;
	ers[1]=1;
	for(i=2;i<100100;i++){
		if(ers[i]==0){
			for(j=i*2;j<100100;j+=i){
				ers[j]=1;
			}
		}
	}
	j=999999;
	for(i=100100;i>=0;i--){
		if(ers[i]==0)j=i;
		mp[i]=j-i;
	}
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	ans=999999999;
	for(i=0;i<n;i++){
		tmp=0;
		for(j=0;j<m;j++){
			tmp+=mp[a[i][j]];
		}
		if(tmp<ans)ans=tmp;
	}
	for(i=0;i<m;i++){
		tmp=0;
		for(j=0;j<n;j++){
			tmp+=mp[a[j][i]];
		}
		if(tmp<ans)ans=tmp;
	}
	printf("%d",ans);
}