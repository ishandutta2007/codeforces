#include<stdio.h>
int n,m;
char map[1010][1010];
int chk[1010][1010];
int len[1010][1010];
int q[1001000][2];
int qs,qe;
int ans;
void qp(int x,int y,int ln){
	if(x>=0&&y>=0&&x<n&&y<m&&map[x][y]!='T'&&chk[x][y]==0){
		chk[x][y]=1;
		len[x][y]=ln+1;
		q[qe][0]=x;
		q[qe][1]=y;
		qe++;
	}
}
int main(){
	int i,j,p;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",map[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]=='E')break;
		}
		if(j!=m)break;
	}
	qp(i,j,0);
	for(;qs<qe;qs++){
		qp(q[qs][0]+1,q[qs][1],len[q[qs][0]][q[qs][1]]);
		qp(q[qs][0]-1,q[qs][1],len[q[qs][0]][q[qs][1]]);
		qp(q[qs][0],q[qs][1]+1,len[q[qs][0]][q[qs][1]]);
		qp(q[qs][0],q[qs][1]-1,len[q[qs][0]][q[qs][1]]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]=='S')break;
		}
		if(j!=m)break;
	}
	p=len[i][j];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]>'0'&&map[i][j]<='9'&&chk[i][j]==1&&len[i][j]<=p){
				ans+=map[i][j]-'0';
			}
		}
	}
	printf("%d",ans);
}