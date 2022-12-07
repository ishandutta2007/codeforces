#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf=1e9;
const int N = 1e5 + 5 ;
int n,c[N],id[N],o[N],bef[N],M,dp[2][N];
bool cmp(int x,int y){return (c[x]&M)>(c[y]&M);}
signed main() {
	n=gi();
	rep(i,1,n)c[i]=gi(),id[i]=i;
	M=1;
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;int now=0;
	for(int k=0;k<=58;++k){
		now^=1;
		rep(i,0,n)dp[now][i]=inf;
		rep(i,1,n)bef[i]=id[i];
		sort(id+1,id+n+1,cmp);
		rep(i,1,n)o[id[i]]=i;
		int a=0,A=0,cntA=0,cntB=0,B=0,b=0;
		rep(i,1,n)if((c[id[i]]>>k)&1)a=i,++cntA;
		cntB=n-cntA;
	//	printf("now case %d\n",k);
		for(int z=0;z<=n;++z){
			if(z){
				if((c[bef[z]]>>k)&1)++A,b=max(b,o[bef[z]]);
				else ++B,a=max(a,o[bef[z]]);
			}
		//	cout<<z<<" "<<a<<" "<<b<<endl;
			dp[now][a]=min(dp[now][a],dp[now^1][z]+cntA+B-A);//0
			dp[now][b]=min(dp[now][b],dp[now^1][z]+cntB+A-B);//1 
		}
		M=(M<<1)+1;
	}
	cout<<dp[now][0]<<endl;
	return 0 ;
}