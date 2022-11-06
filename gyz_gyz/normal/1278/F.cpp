#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int mo=998244353;
const int N=5e3+10;
int f[N][N];
int qk(int x,int y){int r=1;
	for(;y;y>>=1){
		if(y&1)r=1ll*r*x%mo;x=1ll*x*x%mo;
	}return r;
}
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	f[0][0]=1;
	rep(i,1,k)rep(j,1,i)
		f[i][j]=(1ll*f[i-1][j-1]*(n-j+1)+1ll*f[i-1][j]*j)%mo;
	int mq=qk(m,mo-2),nw=1,ans=0;
	rep(i,1,k){
		nw=1ll*nw*mq%mo;
		ans=(ans+1ll*f[k][i]*nw)%mo;
	}
	printf("%d\n",ans);
}