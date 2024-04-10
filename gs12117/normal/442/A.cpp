#include<stdio.h>
int n;
char a[110][6];
int b[110][2];
int ans;
int clb(int x){
	int res=0;
	while(x){
		res+=x%2;
		x/=2;
	}
	return res;
}
int main(){
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
		if(a[i][0]=='R')b[i][0]=0;
		if(a[i][0]=='G')b[i][0]=1;
		if(a[i][0]=='B')b[i][0]=2;
		if(a[i][0]=='Y')b[i][0]=3;
		if(a[i][0]=='W')b[i][0]=4;
		b[i][1]=a[i][1]-'1';
	}
	ans=11;
	for(i=0;i<32;i++){
		for(j=0;j<32;j++){
			for(k=0;k<n;k++){
				for(l=k+1;l<n;l++){
					if(b[k][0]==b[l][0]&&b[k][1]==b[l][1])continue;
					if(b[k][0]!=b[l][0]&&(i>>(b[k][0]))%2)continue;
					if(b[k][0]!=b[l][0]&&(i>>(b[l][0]))%2)continue;
					if(b[k][1]!=b[l][1]&&(j>>(b[k][1]))%2)continue;
					if(b[k][1]!=b[l][1]&&(j>>(b[l][1]))%2)continue;
					break;
				}
				if(l!=n)break;
			}
			if(k==n){
				if(ans>clb(i)+clb(j))ans=clb(i)+clb(j);
			}
		}
	}
	printf("%d",ans);
}