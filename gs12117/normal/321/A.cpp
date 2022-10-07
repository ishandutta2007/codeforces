#include<stdio.h>
int dx,dy;
long long int tdx,tdy;
int x,y;
int vis[410][410];
char s[110];
long long int abs(long long int x){
	if(x>0)return x;
	return -x;
}
int main(){
	int i,j,k;
	scanf("%d%d%s",&dx,&dy,s);
	for(i=0;s[i];i++){
		vis[x+200][y+200]=1;
		if(s[i]=='R')x++;
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if(s[i]=='L')x--;
	}
	tdx=dx;
	tdy=dy;
	if(x==0&&y==0){
		if(vis[dx+200][dy+200]==1)printf("Yes");
		else printf("No");
return 0;
	}
	for(j=0;j<3000000;j++){
		if(abs(tdx)<1000000&&abs(tdy)<1000000){
			while(abs(tdx)<1000000&&abs(tdy)<1000000){
				if(abs(tdx)<150&&abs(tdy)<150&&vis[tdx+200][tdy+200]==1){
					printf("Yes");
					return 0;
				}
				tdx-=x;
				tdy-=y;
			}
			printf("No");
			return 0;
		}
		else{
			tdx-=x*1000;
			tdy-=y*1000;
		}
	}
	printf("No");
	return 0;
}