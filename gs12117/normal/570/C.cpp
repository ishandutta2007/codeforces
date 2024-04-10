#include<stdio.h>
int n,m;
char c[300100];
char tmp[10];
int ans;
int main(){
	int i,p;
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(i=0;i<=n;i++){
		if(c[i]=='.'&&c[i+1]=='.')ans++;
	}
	for(i=0;i<m;i++){
		scanf("%d%s",&p,tmp);
		if(c[p]=='.'&&c[p+1]=='.')ans--;
		if(c[p]=='.'&&c[p-1]=='.')ans--;
		c[p]=tmp[0];
		if(c[p]=='.'&&c[p+1]=='.')ans++;
		if(c[p]=='.'&&c[p-1]=='.')ans++;
		printf("%d\n",ans);
	}
	return 0;
}