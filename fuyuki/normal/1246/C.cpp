#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
const int N=2e3+3,mod=1e9+7;
V check(int&x){x-=mod,x+=x>>31&mod;}
int n,m,ans;
char a[N][N];
int D[N][N],R[N][N],sd[N][N],sr[N][N],cd[N][N],cr[N][N];
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%s",a[i]+1);
}
I txt(){FOR(i,1,n)FOR(j,1,m)if(a[i][j]=='R')return 0;return 1;}
V work(){
	if(a[n][m]=='R')return void(cout<<'0');
	if(n==1||m==1)return void(cout<<txt());
	D[n][m]=R[n][m]=cd[n][m]=cr[n][m]=1;
	ROF(i,n,1)ROF(j,m,1)if(i!=n||j!=m){
		check(D[i][j]=mod+cd[i+1][j]-cd[n-sd[i+1][j]+1][j]);
		check(R[i][j]=mod+cr[i][j+1]-cr[i][m-sr[i][j+1]+1]);
		sd[i][j]=sd[i+1][j]+(a[i][j]=='R');
		sr[i][j]=sr[i][j+1]+(a[i][j]=='R');
		check(cd[i][j]=cd[i+1][j]+R[i][j]);
		check(cr[i][j]=cr[i][j+1]+D[i][j]);
	}
	check(ans=R[1][1]+D[1][1]),cout<<ans;
}
int main(){
	input();
	work();
	return 0;
}