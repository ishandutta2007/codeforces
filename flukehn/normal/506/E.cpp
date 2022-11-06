#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=10007;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=205;
int n,m,cnt,tot,dp[N][N][N],g[N<<1][N<<1]; char s[N];
struct matrix{int p[N<<1][N<<1];}a,b;
void operator *=(matrix &x,const matrix y){
	memset(g,0,sizeof(g));
	rep(i,1,tot)rep(j,i,tot)rep(k,j,tot)
		g[i][k]=(g[i][k]+x.p[i][j]*y.p[j][k])%mo;
	swap(x.p,g);
}
void ksm(matrix x,int y){
	rep(i,1,tot)rep(j,1,tot)b.p[i][j]=(i==j);
	for (;y;y>>=1,x*=x)if(y&1)b*=x;
}
int main(){
	scanf("%s%d",s+1,&m);
	n=strlen(s+1),m+=n;
	rep(i,1,n){
		dp[i][i][0]=1;
		if (i<n&&s[i]==s[i+1])dp[i][i+1][0]=1;
	}
	per(i,1,n-1)
		rep(j,(s[i]==s[i+1])?i+2:i+1,n)
			if(s[i]==s[j])
				rep(k,0,n)dp[i][j][k]=dp[i+1][j-1][k];
			else
				rep(k,1,n)dp[i][j][k]=(dp[i][j-1][k-1]+dp[i+1][j][k-1])%mo;
	int ans=0;
	cnt=n+1>>1;
	For(i,1,n)a.p[i][i]=24,a.p[i][i+1]=1;
	For(i,n,n+cnt)a.p[i][i]=25,a.p[i][i+cnt]=a.p[i-1][i]=1;
	tot=n+(cnt<<1)-1;
	rep(i,n+cnt,tot)a.p[i][i]=26;
	ksm(a,m-1>>1),a*=b;
	For(i,0,n){
		int j=n-i-1>>1,k=a.p[n-i][n+cnt+j];
		if ((m&1)&&!(n-i&1))k=(k-b.p[n-i][n+j]+mo)%mo;
		ans=(ans+dp[1][n][i]*k)%mo;
	}
	cout<<ans<<endl;
}