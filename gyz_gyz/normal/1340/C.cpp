#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e4+10;
const int M=1010;
const ll inf=1e18;
const int mo=998244353;
ll f[N][M];bool v[N][M];int p[N];
int main(){int n,m,g,r;
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d",&p[i]);
	sort(p+1,p+m+1);
	scanf("%d%d",&g,&r);
	queue<pii>q;
	rep(i,1,m)rep(j,1,g)f[i][j]=inf;
	f[1][g]=0;v[1][g]=1;q.push({1,g});
	while(!q.empty()){
		auto x=q.front();q.pop();
		int i=x.fr,j=x.sc;v[i][j]=0;
		if(i<m&&j-p[i+1]+p[i]>=0){
			int ii=i+1,jj=j-p[i+1]+p[i];
			ll xx=f[i][j]+p[i+1]-p[i];
			if(!jj){jj=g;
				if(ii<m)xx+=r;
			}
			if(xx<f[ii][jj]){
				f[ii][jj]=xx;
				if(!v[ii][jj]){
					q.push({ii,jj});v[ii][jj]=1;
				}
			}
		}
		if(i>1&&j-p[i]+p[i-1]>=0){
			int ii=i-1,jj=j-p[i]+p[i-1];
			ll xx=f[i][j]+p[i]-p[i-1];
			if(!jj){jj=g;
				if(ii<m)xx+=r;
			}
			if(xx<f[ii][jj]){
				f[ii][jj]=xx;
				if(!v[ii][jj]){
					q.push({ii,jj});v[ii][jj]=1;
				}
			}
		}
	}
	ll ans=inf;
	rep(i,1,g)ans=min(ans,f[m][i]);
	printf("%lld\n",ans==inf?-1:ans);
}