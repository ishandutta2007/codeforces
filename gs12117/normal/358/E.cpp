#include<stdio.h>
int n,m;
int map[1010][1010];
int strpnt[1001000][2];
int q[1001000][2];
int qs,qe;
int stn;
int ans;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	int i,j,k,l,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&map[i+1][j+1]);
		}
	}
	n+=2;
	m+=2;
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i+1][j+1]==1){
				t=0;
				t+=map[i][j+1];
				t+=map[i+1][j];
				t+=map[i+1][j+2];
				t+=map[i+2][j+1];
				if(t==1||t==3){
					k++;
				}
				if(t==0){
					printf("-1");
					return 0;
				}
			}
		}
	}
	if(k!=0&&k!=2){
		printf("-1");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i+1][j+1]==1){
				t=0;
				t+=map[i][j+1];
				t+=map[i+1][j];
				t+=map[i+1][j+2];
				t+=map[i+2][j+1];
				if(t!=2||(!(((map[i][j+1]==1&&map[i+2][j+1]==1)||(map[i+1][j]==1&&map[i+1][j+2]==1))))){
					strpnt[stn][0]=i;
					strpnt[stn][1]=j;
					stn++;
				}
			}
		}
	}
	if(stn<2){
		printf("-1");
		return 0;
	}
	for(i=1;i<stn;i++){
		strpnt[i][0]-=strpnt[0][0];
		if(strpnt[i][0]<0)strpnt[i][0]=-strpnt[i][0];
		strpnt[i][1]-=strpnt[0][1];
		if(strpnt[i][1]<0)strpnt[i][1]=-strpnt[i][1];
		ans=gcd(strpnt[i][0],ans);
		ans=gcd(strpnt[i][1],ans);
	}
	if(ans<2){
		printf("-1");
		return 0;
	}
	t=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]==1){
				t=1;
				break;
			}
		}
		if(t==1)break;
	}
	qe=1;
	q[0][0]=i;
	q[0][1]=j;
	map[i][j]=0;
	for(qs=0;qs<qe;qs++){
		if(map[q[qs][0]+1][q[qs][1]]==1){
			map[q[qs][0]+1][q[qs][1]]=0;
			q[qe][0]=q[qs][0]+1;
			q[qe][1]=q[qs][1];
			qe++;
		}
		if(map[q[qs][0]-1][q[qs][1]]==1){
			map[q[qs][0]-1][q[qs][1]]=0;
			q[qe][0]=q[qs][0]-1;
			q[qe][1]=q[qs][1];
			qe++;
		}
		if(map[q[qs][0]][q[qs][1]+1]==1){
			map[q[qs][0]][q[qs][1]+1]=0;
			q[qe][0]=q[qs][0];
			q[qe][1]=q[qs][1]+1;
			qe++;
		}
		if(map[q[qs][0]][q[qs][1]-1]==1){
			map[q[qs][0]][q[qs][1]-1]=0;
			q[qe][0]=q[qs][0];
			q[qe][1]=q[qs][1]-1;
			qe++;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]==1){
				printf("-1");
				return 0;
			}
		}
	}
	for(i=2;i<=ans;i++){
		if(ans%i==0)printf("%d ",i);
	}
	return 0;
}