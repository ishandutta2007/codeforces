#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
const int MAXN = 2010;
inl int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,k,ans,a[MAXN][MAXN],sum1[MAXN][MAXN],sum2[MAXN][MAXN],sum3[MAXN][MAXN],sum4[MAXN][MAXN];
char Map[MAXN][MAXN];
inline int check1(int x){return sum1[x][n]==0;}
inline int check2(int x){return sum2[n][x]==0;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",Map[i]+1);
		for(int j=1;j<=n;j++) a[i][j]=(Map[i][j]=='B');
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    	sum1[i][j]=sum1[i][j-1]+a[i][j],sum2[i][j]=sum2[i-1][j]+a[i][j];
	
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++){
	    	if(j<=n-k+1) sum3[i][j]=(sum1[i][j+k-1]-sum1[i][j-1]==sum1[i][n])-check1(i);
	    	if(i<=n-k+1) sum4[i][j]=(sum2[i+k-1][j]-sum2[i-1][j]==sum2[n][j])-check2(j);
	    }
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++) sum3[i][j]+=sum3[i-1][j],sum4[i][j]+=sum4[i][j-1];
	for(int i=1;i<=n-k+1;i++)
	    for(int j=1;j<=n-k+1;j++) ans=max(ans,sum4[i][j+k-1]-sum4[i][j-1]+sum3[i+k-1][j]-sum3[i-1][j]);
	for(int i=1;i<=n;i++) ans+=check1(i)+check2(i);
	cout<<ans<<'\n';
	return 0;
}