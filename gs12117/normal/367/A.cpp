#include<stdio.h>
int n,m;
char a[100100];
int b[100100][3];
int q[100100][2];
bool diff(int x,int y){
	if(y-x<3)return 1;
	if(b[y][0]-b[x][0]<(y-x)/3)return 0;
	if(b[y][1]-b[x][1]<(y-x)/3)return 0;
	if(b[y][2]-b[x][2]<(y-x)/3)return 0;
	if(b[y][0]-b[x][0]>(y-x+2)/3)return 0;
	if(b[y][1]-b[x][1]>(y-x+2)/3)return 0;
	if(b[y][2]-b[x][2]>(y-x+2)/3)return 0;
	return 1;
}
int main(){
	int i,j;
	scanf("%s",a);
	for(n=0;a[n];n++);
	for(i=0;i<n;i++){
		b[i+1][0]=b[i][0];
		b[i+1][1]=b[i][1];
		b[i+1][2]=b[i][2];
		b[i+1][a[i]-'x']++;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&q[i][0],&q[i][1]);
		if(diff(q[i][0]-1,q[i][1])){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
}