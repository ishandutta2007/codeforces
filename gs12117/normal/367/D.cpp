#include<stdio.h>
int n,m,d;
int b[22][100100];
int s[22];
int a[100100];
int c[1<<20];
int bn[22];
int ans;
int sb(int x){
	int i,res=0;
	for(i=0;i<m;i++){
		if(x&(1<<i))res++;
	}
	return res;
}
int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<m;i++){
		scanf("%d",&s[i]);
		for(j=0;j<s[i];j++){
			scanf("%d",&b[i][j]);
			a[b[i][j]-1]=i;
		}
	}
	j=0;
	for(i=0;i<d;i++){
		if(bn[a[i]]==0)j+=(1<<(a[i]));
		bn[a[i]]++;
	}
	for(i=0;i<n-d;i++){
		c[(1<<m)-j-1]=1;
		if(bn[a[i+d]]==0)j+=(1<<(a[i+d]));
		bn[a[i+d]]++;
		bn[a[i]]--;
		if(bn[a[i]]==0)j-=(1<<(a[i]));
	}
	c[(1<<m)-j-1]=1;
	for(i=0;i<m;i++){
		for(j=0;j<(1<<m);j++){
			if((j&(1<<i))==0&&c[j+(1<<i)]==1){
				c[j]=1;
			}
		}
	}
	ans=m;
	for(i=0;i<(1<<m);i++){
		if(c[i]==0&&sb(i)<ans)ans=sb(i);
	}
	printf("%d",ans);
}