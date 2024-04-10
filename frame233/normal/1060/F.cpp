#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=55;
std::vector<int> e[N];
double dp[N][N],C[N][N],tp[N];
int dfs(int x,int fa){
	int s=0;dp[x][0]=1;
	for(auto v:e[x])if(v!=fa){
		int tmp=dfs(v,x);for(int i=0;i<=s+tmp;++i)tp[i]=0;
		for(int i=0;i<=s;++i){
			for(int j=0;j<=tmp;++j){
				tp[i+j]+=C[i+j][i]*C[s-i+tmp-j][s-i]*dp[x][i]*dp[v][j];
			}
		}
		for(int i=0;i<=s+tmp;++i)dp[x][i]=tp[i];
		s+=tmp;
	}
	if(fa){
		for(int i=0;i<=s+1;++i)tp[i]=0;
		for(int i=0;i<=s;++i){
			for(int j=0;j<=s+1;++j){
				if(i<j)tp[j]+=dp[x][j-1];
				else tp[j]+=0.5*dp[x][i];
			}
		}
		++s;for(int i=0;i<=s;++i)dp[x][i]=tp[i];
	}
	return s;
}
int main(){
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	int n;read(n);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	double fac=1;for(int i=1;i<n;++i)fac*=i;
	for(int i=1;i<=n;++i)memset(dp,0,sizeof(dp)),dfs(i,0),printf("%.8lf\n",dp[i][0]/fac);
	return 0;
}