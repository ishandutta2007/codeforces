#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 2010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,m,s,t,X,Y,d[N*N],dx[N*N],dy[N*N];char ch[N];bool v[N][N];
void f(int x,int y,int z){
	if((v[x][y])||(z+dy[1]-y>X*2)||(z+y-dy[1]>Y*2))return;
	t++;dx[t]=x;dy[t]=y;d[t]=z;v[x][y]=1;
	rep(i,x+1,n){
		if(v[i][y])break;
		t++;dx[t]=i;dy[t]=y;d[t]=z;v[i][y]=1;
	}
	dep(i,x-1,1){
		if(v[i][y])break;
		t++;dx[t]=i;dy[t]=y;d[t]=z;v[i][y]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,n+1)v[i][0]=v[i][m+1]=1;
	rep(i,0,m+1)v[0][i]=v[n+1][i]=1;
	scanf("%d%d",&dx[1],&dy[1]);
	scanf("%d%d",&X,&Y);
	s=t=1;v[dx[1]][dy[1]]=1;
	rep(i,1,n){
		scanf("%s",ch+1);
		rep(j,1,m)if(ch[j]=='*')v[i][j]=1;
	}
	rep(i,dx[1]+1,n){
		if(v[i][dy[1]])break;
		t++;dx[t]=i;dy[t]=dy[1];d[t]=0;v[i][dy[1]]=1;
	}
	dep(i,dx[1]-1,1){
		if(v[i][dy[1]])break;
		t++;dx[t]=i;dy[t]=dy[1];d[t]=0;v[i][dy[1]]=1;
	}
	while(s<=t){
		f(dx[s],dy[s]-1,d[s]+1);f(dx[s],dy[s]+1,d[s]+1);s++;
	}
	printf("%d\n",t);
}