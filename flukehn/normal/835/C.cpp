#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
const int N=100;
int f[13][N+10][N+10],C,n;
struct node{
	int x,y,s;
}p[1000001];
void calc(int x){
	if(x)for(int i=1;i<=n;i++){p[i].s++;if(p[i].s>C)p[i].s=0;}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			f[x][i][j]=0;
	for(int i=1;i<=n;i++){
		f[x][p[i].x][p[i].y]+=p[i].s;
	}
}
void solve(int x){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			f[x][i][j]+=f[x][i-1][j]+f[x][i][j-1]-f[x][i-1][j-1]; 
		}
}
int main(){
	n=rd();
	int q=rd();
	C=rd();
	for(int i=1;i<=n;i++){
		p[i].x=rd(),p[i].y=rd(),p[i].s=rd();
	}
	for(int i=0;i<=C;i++)calc(i),solve(i);
	while(q--){
		int t=rd()%(C+1),a=rd(),b=rd(),c=rd(),d=rd();
		printf("%d\n",f[t][c][d]+f[t][a-1][b-1]-f[t][a-1][d]-f[t][c][b-1]);
	}
}