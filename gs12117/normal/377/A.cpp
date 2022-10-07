#include<stdio.h>
int n,m,req;
int ecn;
char a[510][510];
int chk[510][510];
int q[260000][2];
int qs,qe;
void qpush(int x,int y){
	if(x<0||y<0||x>=n||y>=m)return;
	if(a[x][y]!='X'||chk[x][y]==1)return;
	chk[x][y]=1;
	q[qe][0]=x;
	q[qe][1]=y;
	qe++;
}
int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&req);
	for(i=0;i<n;i++){
		scanf("%s",&a[i]);
		for(j=0;j<m;j++){
			if(a[i][j]=='.'){
				a[i][j]='X';
				ecn++;
			}
		}
	}
	ecn-=req;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]=='X')break;
		}
		if(j!=m)break;
	}
	q[0][0]=i;
	q[0][1]=j;
	qs=0;
	qe=1;
	for(;qs<ecn;qs++){
		a[q[qs][0]][q[qs][1]]='.';
		qpush(q[qs][0]+1,q[qs][1]);
		qpush(q[qs][0]-1,q[qs][1]);
		qpush(q[qs][0],q[qs][1]+1);
		qpush(q[qs][0],q[qs][1]-1);
	}
	for(i=0;i<n;i++){
		printf("%s\n",a[i]);
	}
}