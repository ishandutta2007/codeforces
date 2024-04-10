#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
#define y1 ysgh
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,Q,R[N][N],G[N][N],Y[N][N],B[N][N];
char mp[N][N];
int ok[N/2][N][N];
void init(int s[][N]){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1]; 
		}
	}	
}
inline bool Ask1(int x1,int y1,int x2,int y2,int s[][N]){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]==(x2-x1+1)*(y2-y1+1);
}
inline bool Ask2(int x1,int y1,int x2,int y2,int s[][N]){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]>0;
}
int Solve(){
	int x1=read(),y1=read(),x2=read(),y2=read();
	for(int i=min(x2-x1+1,y2-y1+1)>>1;i>=1;--i){
		if(Ask2(x1+2*i-1,y1+2*i-1,x2,y2,ok[i]))return 4*i*i;
	}
	return 0;
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(mp[i][j]=='R')++R[i][j];
			if(mp[i][j]=='G')++G[i][j];
			if(mp[i][j]=='Y')++Y[i][j];
			if(mp[i][j]=='B')++B[i][j];	
		}	
	}
	init(R),init(Y),init(G),init(B);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;(k<<1)<=min(i,j);++k){
				if(Ask1(i-2*k+1,j-2*k+1,i-k,j-k,R) &&
				   Ask1(i-k+1  ,j-2*k+1,i  ,j-k,Y) &&
				   Ask1(i-2*k+1,j-k+1  ,i-k,j  ,G) &&
				   Ask1(i-k+1  ,j-k+1  ,i  ,j  ,B))
				   ++ok[k][i][j];
			}
		}	
	}
	for(int i=1;(i<<1)<=min(n,m);++i){
		init(ok[i]);
	}
	while(Q--){
		printf("%d\n",Solve());
	}
	return 0;
}