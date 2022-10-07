#include<stdio.h>
int n,m;
char a[2010][2010];
int b[2010][2010];
int q[4100000][2];
int qs,qe;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i+1]+1);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]=='.'){
				if(a[i][j+1]=='.')b[i][j]++;
				if(a[i][j-1]=='.')b[i][j]++;
				if(a[i+1][j]=='.')b[i][j]++;
				if(a[i-1][j]=='.')b[i][j]++;
				if(b[i][j]==1){
					q[qe][0]=i;
					q[qe][1]=j;
					qe++;
				}
			}
		}
	}
	for(qs=0;qs<qe;qs++){
		i=q[qs][0];
		j=q[qs][1];
		if(a[i][j]=='.'){
			if(a[i][j+1]=='.'){
				a[i][j]='<';
				a[i][j+1]='>';
				j++;
			}
			else if(a[i][j-1]=='.'){
				a[i][j-1]='<';
				a[i][j]='>';
				j--;
			}
			else if(a[i+1][j]=='.'){
				a[i][j]='^';
				a[i+1][j]='v';
				i++;
			}
			else if(a[i-1][j]=='.'){
				a[i-1][j]='^';
				a[i][j]='v';
				i--;
			}
			else goto imp;
			b[i+1][j]--;
			if(b[i+1][j]==1){
				q[qe][0]=i+1;
				q[qe][1]=j;
				qe++;
			}
			b[i-1][j]--;
			if(b[i-1][j]==1){
				q[qe][0]=i-1;
				q[qe][1]=j;
				qe++;
			}
			b[i][j+1]--;
			if(b[i][j+1]==1){
				q[qe][0]=i;
				q[qe][1]=j+1;
				qe++;
			}
			b[i][j-1]--;
			if(b[i][j-1]==1){
				q[qe][0]=i;
				q[qe][1]=j-1;
				qe++;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]=='.'){
				goto imp;
			}
		}
	}
	for(i=1;i<=n;i++){
		puts(a[i]+1);
	}
	return 0;
imp:
	printf("Not unique");
	return 0;
}