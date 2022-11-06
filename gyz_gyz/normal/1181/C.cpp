#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e3+10;
const int mo=998244353;
char s[N][N],s2[N][N],s3[N][N];int d1[N][N],d2[N][N],d3[N][N],a[N][N];bool ok[N][N];
int main(){int n,m;ll ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	dep(i,n,1){
		rep(j,1,m){
			if(s[i][j]!=s[i+1][j]){
				d1[i][j]=1;d2[i][j]=d1[i+1][j];d3[i][j]=d2[i+1][j];
				s2[i][j]=s[i+1][j];s3[i][j]=s2[i+1][j];
			}else{
				d1[i][j]=d1[i+1][j]+1,d2[i][j]=d2[i+1][j],d3[i][j]=d3[i+1][j];
				s2[i][j]=s2[i+1][j];s3[i][j]=s3[i+1][j];
			}
		}
	}
	rep(i,1,n)rep(j,1,m){
		if(d1[i][j]!=d2[i][j]||d3[i][j]<d2[i][j])continue;ok[i][j]=1;
		if(s[i][j]==s[i][j-1]&&s2[i][j]==s2[i][j-1]&&s3[i][j]==s3[i][j-1]&&d1[i][j]==d1[i][j-1]&&ok[i][j-1]){
			ans+=(a[i][j]=a[i][j-1]+1);
		}else ans+=(a[i][j]=1);
	}
	printf("%lld\n",ans);
}