#include<stdio.h>
int n;
int a[1001000];
int b[1001000];
int c[1001000];
int ans;
int main(){
	int i,j;
	scanf("%d",&n);
	n++;
	for(i=2;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=1;
		c[i]=0;
		j=i;
		if(ans<b[j])ans=b[j];
		while(a[j]!=1){
			if(ans<b[j])ans=b[j];
			if(ans<b[a[j]])ans=b[a[j]];
			if(b[a[j]]<b[j]){
				b[a[j]]=b[j];
				c[a[j]]=1;
			}
			else if(c[a[j]]==1&&b[a[j]]==b[j]){
				b[a[j]]=b[j]+1;
				c[a[j]]=0;
			}
			else if(c[a[j]]==0&&b[a[j]]==b[j]){
				c[a[j]]=1;
				break;
			}
			else break;
			if(ans<b[a[j]])ans=b[a[j]];
			j=a[j];
		}
		printf("%d ",ans);
	}
}