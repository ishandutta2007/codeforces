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
const int N=2e5+10;
const int mo=1e9+7;
inline void add(int&x,const int&y){if((x+=y)>=mo)x-=mo;}
int main(){int n,m,t1=0,t2=0,t3=0;
	scanf("%d%d",&n,&m);
	int t[n+1],d[n+1];
	rep(i,1,n){
		scanf("%d%d",&t[i],&d[i]);
		if(d[i]==1)++t1;else if(d[i]==2)++t2;else ++t3;
	}
	int f[t1+1][t2+1][t3+1][m+1];
	memset(f,0,sizeof(f));
	f[0][0][0][0]=1;t1=t2=t3=0;
	rep(i,1,n){
		if(d[i]==1){
			dep(j,m,t[i])rep(i1,0,t1)rep(i2,0,t2)rep(i3,0,t3)add(f[i1+1][i2][i3][j],f[i1][i2][i3][j-t[i]]);++t1;
		}else if(d[i]==2){
			dep(j,m,t[i])rep(i1,0,t1)rep(i2,0,t2)rep(i3,0,t3)add(f[i1][i2+1][i3][j],f[i1][i2][i3][j-t[i]]);++t2;
		}else if(d[i]==3){
			dep(j,m,t[i])rep(i1,0,t1)rep(i2,0,t2)rep(i3,0,t3)add(f[i1][i2][i3+1][j],f[i1][i2][i3][j-t[i]]);++t3;
		}
	}ll ans=0,g[t1+1][t2+1][t3+1][3];
	memset(g,0,sizeof(g));
	if(t1)g[1][0][0][0]=1;
	if(t2)g[0][1][0][1]=1;
	if(t3)g[0][0][1][2]=1;
	rep(i,0,t1)rep(j,0,t2)rep(k,0,t3)rep(l,0,2)if(g[i][j][k][l]){
		(ans+=g[i][j][k][l]*f[i][j][k][m])%=mo;
		if(l&&i<t1)(g[i+1][j][k][0]+=g[i][j][k][l]*(i+1))%=mo;
		if(l!=1&&j<t2)(g[i][j+1][k][1]+=g[i][j][k][l]*(j+1))%=mo;
		if(l!=2&&k<t3)(g[i][j][k+1][2]+=g[i][j][k][l]*(k+1))%=mo;
	}
	printf("%lld\n",ans);
}