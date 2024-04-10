#include<stdio.h>
int n;
char a[210];
int ans;
int exec(int start,int end){
	int i,x,y;
	x=0;
	y=0;
	for(i=start;i<=end;i++){
		if(a[i]=='U')x++;
		if(a[i]=='R')y++;
		if(a[i]=='D')x--;
		if(a[i]=='L')y--;
	}
	if(x==0&&y==0)return 1;
	return 0;
}
int main(){
	int i,j;
	scanf("%d%s",&n,a);
	ans=0;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			ans+=exec(i,j);
		}
	}
	printf("%d",ans);
	return 0;
}