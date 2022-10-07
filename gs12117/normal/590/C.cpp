#include<stdio.h>
int n,m;
char map[1010][1010];
int q[1100000][2];
int dist[3][1010][1010];
int chk[1010][1010];
int qs,qe;
int s[3];
int ans;
void qpush(int x,int y,int p,int d){
	if(x<0||x>=n||y<0||y>=m||chk[x][y]==1||map[x][y]=='#')return;
	chk[x][y]=1;
	dist[p][x][y]=d;
	q[qe][0]=x;
	q[qe][1]=y;
	qe++;
}
int main(){
	int i,j,p;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",map[i]);
	}
	for(p=0;p<3;p++){
		qs=0;
		qe=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				chk[i][j]=0;
				dist[p][i][j]=99999999;
				if(map[i][j]=='1'+p){
					chk[i][j]=1;
					dist[p][i][j]=0;
					q[qe][0]=i;
					q[qe][1]=j;
					qe++;
				}
			}
		}
		while(qs<qe){
			qpush(q[qs][0]+1,q[qs][1],p,dist[p][q[qs][0]][q[qs][1]]+1);
			qpush(q[qs][0]-1,q[qs][1],p,dist[p][q[qs][0]][q[qs][1]]+1);
			qpush(q[qs][0],q[qs][1]+1,p,dist[p][q[qs][0]][q[qs][1]]+1);
			qpush(q[qs][0],q[qs][1]-1,p,dist[p][q[qs][0]][q[qs][1]]+1);
			qs++;
		}
	}
	s[0]=9999999;
	s[1]=9999999;
	s[2]=9999999;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]=='1'){
				if(s[0]>dist[1][i][j]){
					s[0]=dist[1][i][j];
				}
				if(s[1]>dist[2][i][j]){
					s[1]=dist[2][i][j];
				}
			}
			if(map[i][j]=='2'){
				if(s[0]>dist[0][i][j]){
					s[0]=dist[0][i][j];
				}
				if(s[2]>dist[2][i][j]){
					s[2]=dist[2][i][j];
				}
			}
			if(map[i][j]=='3'){
				if(s[1]>dist[0][i][j]){
					s[1]=dist[0][i][j];
				}
				if(s[2]>dist[1][i][j]){
					s[2]=dist[1][i][j];
				}
			}
		}
	}
	s[0]--;
	s[1]--;
	s[2]--;
	if(s[0]>1000000||s[1]>1000000||s[2]>1000000){
		printf("-1");
		return 0;
	}
	ans=s[0]+s[1];
	if(ans>s[0]+s[2])ans=s[0]+s[2];
	if(ans>s[1]+s[2])ans=s[1]+s[2];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(ans>dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2){
				ans=dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2;
			}
		}
	}
	printf("%d",ans);
	return 0;
}