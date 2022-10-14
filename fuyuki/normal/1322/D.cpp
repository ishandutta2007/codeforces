#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=4e3+2,K=2047,INF=0x3f3f3f3f;
int n,m,ans;
int d[N],s[N],c[N],t[N],f[N][N];
void cmax(int&x,int y){if(x-y>>31)x=y;}
int main(){
	scanf("%d%d",&n,&m),t[0]=n,m+=n;
	ROF(i,n,1)scanf("%d",d+i);
	ROF(i,n,1)scanf("%d",s+i);
	FOR(i,1,m)scanf("%d",c+i);
	FOR(i,0,m)FOR(j,1,n)f[i][j]=-INF;
	FOR(i,1,n)t[i]=t[i-1]>>1;
	FOR(i,1,n){
		int p=d[i];
		ROF(j,n,1)cmax(f[p][j],f[p][j-1]+c[p]-s[i]);
		FOR(j,p,m)FOR(k,0,t[j-p])cmax(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	cout<<f[m][0];
	return 0;
}