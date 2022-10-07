#include<stdio.h>
int n,m;
int mx[510][510];
int edge[300000][2];
char str[510];
int main(){
	int i,j,flag=0;
	int a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		a--;
		b--;
		mx[a][b]=1;
		mx[b][a]=1;
	}
	for(i=0;i<n;i++)str[i]='a';
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j&&mx[i][j]==0)break;
		}
		if(j==n)str[i]='b';
		else if(flag==0){
			flag=1;
			for(j=0;j<n;j++){
				if(i!=j&&mx[i][j]==0)str[j]='c';
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if((str[i]=='a'&&str[j]=='c')||(str[i]=='c'&&str[j]=='a')){
				if(mx[i][j]==1){
					puts("No");
					return 0;
				}
			}
			else{
				if(mx[i][j]==0){
					puts("No");
					return 0;
				}
			}
		}
	}
	str[n]=0;
	puts("Yes");
	printf("%s",str);
	return 0;
}