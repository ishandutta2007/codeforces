#include<stdio.h>
int n,m,q;
char p[510][510];
int lr[510][510];
int ud[510][510];
int ax,ay,bx,by;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",p[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m-1;j++){
			if(p[i][j]=='.'&&p[i][j+1]=='.')lr[i+1][j+1]=1;
			lr[i+1][j+1]+=lr[i+1][j]+lr[i][j+1]-lr[i][j];
		}
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<m;j++){
			if(p[i][j]=='.'&&p[i+1][j]=='.')ud[i+1][j+1]=1;
			ud[i+1][j+1]+=ud[i+1][j]+ud[i][j+1]-ud[i][j];
		}
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d%d",&ax,&ay,&bx,&by);
		printf("%d\n",lr[bx][by-1]-lr[bx][ay-1]-lr[ax-1][by-1]+lr[ax-1][ay-1]+ud[bx-1][by]-ud[bx-1][ay-1]-ud[ax-1][by]+ud[ax-1][ay-1]);
	}
	return 0;
}